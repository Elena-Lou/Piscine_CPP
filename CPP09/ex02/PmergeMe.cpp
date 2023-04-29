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

void PmergeMe::sortVector( int ac, char** av ) {

        struct timespec start, end;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

        this->initialiseContainers(ac, av);
		this->divideIntoPairs();
		this->sortEachPair();
        int size = this->getSize();
        this->recursivelySortPairs(size);
        this->splitPairs();
        this->insertPending();
		        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        double elapsedTime = (1000 * end.tv_sec + 1e-6 * end.tv_nsec) - (1000 * start.tv_sec + 1e-6 * start.tv_nsec);
        std::cout << std::setprecision(12) << "Time to process a range of " << size*2 <<  " elements with std::vector : " << elapsedTime << "ms" << std::endl;
}

void PmergeMe::initialiseContainers( int ac, char** arg ) {

    int value;

    for (int i = 1; i < ac; i++)
    {
        for (size_t j = 0; j < std::strlen(arg[i]); j++)
        {
            if (!std::isdigit(arg[i][j]))
				throw PmergeMe::BadInputException();
        }
        value = std::atoi(arg[i]);
		if (value < 0)
			throw PmergeMe::BadInputException();
        this->_argVector.push_back(value);
    }
	std::cout << "Before : ";
	this->printVector(this->_argVector);
	this->_isEven = this->isEven();
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
}

void PmergeMe::sortEachPair( void ) {

	std::vector<std::pair<int, int> >::iterator it;
	for (it = this->_pairsVector.begin(); it != this->_pairsVector.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::recursivelySortPairs( int size ) {
	
	//base case to stop recursivity
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

	std::vector<std::pair<int, int> >::iterator it;

	for (it = this->_pairsVector.begin(); it != this->_pairsVector.end(); it++)
		this->_sortedVector.push_back(it->second);
}

void PmergeMe::findSpot ( std::pair<int,int> pair ) {

	std::vector<int>::iterator upTo = std::find(this->_sortedVector.begin(), this->_sortedVector.end(), pair.second);
	std::vector<int>::iterator valuePos = std::lower_bound(this->_sortedVector.begin(), upTo, pair.first);

	this->_sortedVector.insert(valuePos, pair.first);
}

void PmergeMe::insertPending( void ) {

	std::vector<int>::iterator it = this->_sortedVector.begin();
	this->_sortedVector.insert(it, this->_pairsVector[0].first);

	std::vector<std::pair<int, int> >::iterator penValue;
	
	for (penValue = this->_pairsVector.begin() + 1; penValue != this->_pairsVector.end(); penValue++)
		findSpot(*penValue);

	if (this->_isEven == false)
	{
		std::vector<int>::iterator valuePos = std::lower_bound(this->_sortedVector.begin(), this->_sortedVector.end(), this->_straggler);
		this->_sortedVector.insert(valuePos, this->_straggler);
	}
	std::cout << "\nAfter : ";
	this->printVector(this->_sortedVector);
}

const char* PmergeMe::BadInputException::what( void ) const throw() {

	return ("Error : bad input");
}