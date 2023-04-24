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

int PmergeMe::getStraggler( void ) const {

	return this->_straggler;
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

const char* PmergeMe::BadInputException::what( void ) const throw() {

	return ("Error : bad input");
}