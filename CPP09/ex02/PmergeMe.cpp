#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _argVector(0) {

}

PmergeMe::PmergeMe( PmergeMe const & src ) : _argVector(src._argVector) {

    *this = src;
}

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs ) {

    if (this != &rhs)
    {
        this->_argVector = rhs._argVector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::printVector( void ) {

	for (std::vector<int>::iterator it = _argVector.begin(); it != _argVector.end(); it++)
    {
       	std::cout << "[" << *it << "] ";
    }
	std::cout << std::endl;
    
}

void PmergeMe::printVector( std::vector<int> vector ) {

	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
       	std::cout << "[" << *it << "] ";
    }
	std::cout << std::endl;
    
}

void PmergeMe::printPairsVector( void ) {

	std::vector<std::pair<int, int> >::iterator it;
	for (it = _pairsVector.begin(); it != _pairsVector.end(); it++)
    {
       	std::cout << "[" << it->first << ", " << it->second << "] ";
    }
	std::cout << std::endl;
    
}

int PmergeMe::getStraggler( void ) const {

	return this->_straggler;
}

int PmergeMe::getSize( void ) const {

	return this->_pairsVector.size();
}

void PmergeMe::initialiseContainers( int ac, char** arg ) {

    std::cout << "INIT CONTAINERS" << std::endl;
    int value;

    for (int i = 1; i < ac; i++)
    {
        for (size_t j = 0; j < std::strlen(arg[i]); j++)
        {
            if (!std::isdigit(arg[i][j]))
				throw PmergeMe::BadInputException();
            // std::cout << "av[" << i << "][" << j << "] : " << arg[i][j] << std::endl;
        }
        value = std::atoi(arg[i]);
        // std::cout << "value = " << value << std::endl;
        this->_argVector.push_back(value);
    }
	this->printVector();
}

bool PmergeMe::isEven( void ) {

	int size = this->_argVector.size();
	if (size % 2 == 1)
	{
		this->_straggler = this->_argVector.back();
		this->_argVector.pop_back();
		return false;
	}
	return true;
}

void PmergeMe::divideIntoPairs( void ) {

	std::vector<int>::iterator first;

	for (std::vector<int>::iterator second = this->_argVector.begin();\
	second != this->_argVector.end(); second++)
	{
		first = second;
		second++;
		this->_pairsVector.push_back(std::make_pair(*first, *second));
	}
	this->printPairsVector();

}

void PmergeMe::sortEachPair( void ) {

	std::cout << "SORT EACH PAIR" << std::endl;
	std::vector<std::pair<int, int> >::iterator it;
	for (it = this->_pairsVector.begin(); it != this->_pairsVector.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	this->printPairsVector();
}

void PmergeMe::recursivelySortPairs( int size ) {
	
	//base case to stop recursivity to go any deeper
	if (size <= 1)
		return;

	this->recursivelySortPairs(size - 1);

	std::pair<int, int> last = this->_pairsVector[size - 1];
	int j = size - 2;

	while (j >= 0 && this->_pairsVector[j].second > last.second)
	{
		this->_pairsVector[j + 1] = this->_pairsVector[j];
		j--;
	}
	this->_pairsVector[j + 1] = last;
}

void PmergeMe::splitPairs( void ) {

	std::vector<int> sortedVector;
	std::vector<int> pendingValues;

	std::vector<std::pair<int, int> >::iterator it;

	for (it = this->_pairsVector.begin(); it != this->_pairsVector.end(); it++)
	{
		pendingValues.push_back(it->first);
		sortedVector.push_back(it->second);
	}
	this->_pairsVector.clear();
	this->printPairsVector();
	this->printVector(sortedVector);
	this->printVector(pendingValues);
}

const char* PmergeMe::BadInputException::what( void ) const throw() {

	return ("Error : bad input");
}