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

/* VECTOR FUNCTIONS */

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

void PmergeMe::sortVector( int ac, char** av ) {

        struct timespec start, end;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

        this->initialiseVector(ac, av);
		this->divideIntoPairsVector();
		this->sortEachPairVector();
        int size = this->_pairsVector.size();
        this->recursivelySortPairsVector(size);
        this->splitPairsVector();
        this->insertPendingVector();
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        double elapsedTime = (1000 * end.tv_sec + 1e-6 * end.tv_nsec) - (1000 * start.tv_sec + 1e-6 * start.tv_nsec);
        std::cout << std::setprecision(12) << "Time to process a range of " << size*2 <<  " elements with std::vector : " << elapsedTime << "ms\n" << std::endl;
}

void PmergeMe::initialiseVector( int ac, char** arg ) {

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
	this->_isEven = this->isEvenVector();
}

bool PmergeMe::isEvenVector( void ) {

	int size = this->_argVector.size();
	if (size % 2 == 1)
	{
		this->_straggler = this->_argVector.back();
		this->_argVector.pop_back();
		return false;
	}
	return true;
}

void PmergeMe::divideIntoPairsVector( void ) {

	std::vector<int>::iterator first;

	for (std::vector<int>::iterator second = this->_argVector.begin();\
	second != this->_argVector.end(); second++)
	{
		first = second;
		second++;
		this->_pairsVector.push_back(std::make_pair(*first, *second));
	}
}

void PmergeMe::sortEachPairVector( void ) {

	std::vector<std::pair<int, int> >::iterator it;
	for (it = this->_pairsVector.begin(); it != this->_pairsVector.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::recursivelySortPairsVector( int size ) {
	
	//base case to stop recursivity
	if (size <= 1)
		return;

	this->recursivelySortPairsVector(size - 1);

	std::pair<int, int> last = this->_pairsVector[size - 1];
	int j = size - 2;

	while (j >= 0 && this->_pairsVector[j].second > last.second)
	{
		this->_pairsVector[j + 1] = this->_pairsVector[j];
		j--;
	}
	this->_pairsVector[j + 1] = last;
}

void PmergeMe::splitPairsVector( void ) {

	std::vector<std::pair<int, int> >::iterator it;

	for (it = this->_pairsVector.begin(); it != this->_pairsVector.end(); it++)
		this->_sortedVector.push_back(it->second);
}

void PmergeMe::findSpotVector ( std::pair<int,int> pair ) {

	std::vector<int>::iterator upTo = std::find(this->_sortedVector.begin(), this->_sortedVector.end(), pair.second);
	std::vector<int>::iterator valuePos = std::lower_bound(this->_sortedVector.begin(), upTo, pair.first);

	this->_sortedVector.insert(valuePos, pair.first);
}

void PmergeMe::insertPendingVector( void ) {

	std::vector<int>::iterator it = this->_sortedVector.begin();
	this->_sortedVector.insert(it, this->_pairsVector[0].first);

	std::vector<std::pair<int, int> >::iterator penValue;
	
	for (penValue = this->_pairsVector.begin() + 1; penValue != this->_pairsVector.end(); penValue++)
		findSpotVector(*penValue);

	if (this->_isEven == false)
	{
		std::vector<int>::iterator valuePos = std::lower_bound(this->_sortedVector.begin(), this->_sortedVector.end(), this->_straggler);
		this->_sortedVector.insert(valuePos, this->_straggler);
	}
	std::cout << "\nAfter : ";
	this->printVector(this->_sortedVector);
	std::cout << std::endl;
}

/* DEQUE FUNCTIONS */

void PmergeMe::printDeque( std::deque<int> deque ) {

	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    {
       	std::cout << "[" << *it << "] ";
    }
	std::cout << std::endl;
    
}

void PmergeMe::printPairsDeque( void ) {

	std::deque<std::pair<int, int> >::iterator it;
	for (it = _pairsDeque.begin(); it != _pairsDeque.end(); it++)
    {
       	std::cout << "[" << it->first << ", " << it->second << "] ";
    }
	std::cout << std::endl;
}

void PmergeMe::sortDeque( int ac, char** av ) {

        struct timespec start, end;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

        this->initialiseDeque(ac, av);
		this->divideIntoPairsDeque();
		this->sortEachPairDeque();
        int size = this->_pairsDeque.size();
        this->recursivelySortPairsDeque(size);
        this->splitPairsDeque();
        this->insertPendingDeque();
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        double elapsedTime = (1000 * end.tv_sec + 1e-6 * end.tv_nsec) - (1000 * start.tv_sec + 1e-6 * start.tv_nsec);
        std::cout << std::setprecision(12) << "Time to process a range of " << size*2 <<  " elements with std::deque : " << elapsedTime << "ms" << std::endl;
}

void PmergeMe::initialiseDeque( int ac, char** arg ) {

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
        this->_argDeque.push_back(value);
    }
	std::cout << "Before : ";
	this->printDeque(this->_argDeque);
	this->_isEven = this->isEvenDeque();
}

bool PmergeMe::isEvenDeque( void ) {

	int size = this->_argDeque.size();
	if (size % 2 == 1)
	{
		this->_straggler = this->_argDeque.back();
		this->_argDeque.pop_back();
		return false;
	}
	return true;
}

void PmergeMe::divideIntoPairsDeque( void ) {

	std::deque<int>::iterator first;

	for (std::deque<int>::iterator second = this->_argDeque.begin();\
	second != this->_argDeque.end(); second++)
	{
		first = second;
		second++;
		this->_pairsDeque.push_back(std::make_pair(*first, *second));
	}
}

void PmergeMe::sortEachPairDeque( void ) {

	std::deque<std::pair<int, int> >::iterator it;
	for (it = this->_pairsDeque.begin(); it != this->_pairsDeque.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::recursivelySortPairsDeque( int size ) {
	
	//base case to stop recursivity
	if (size <= 1)
		return;

	this->recursivelySortPairsDeque(size - 1);

	std::pair<int, int> last = this->_pairsDeque[size - 1];
	int j = size - 2;

	while (j >= 0 && this->_pairsDeque[j].second > last.second)
	{
		this->_pairsDeque[j + 1] = this->_pairsDeque[j];
		j--;
	}
	this->_pairsDeque[j + 1] = last;
}

void PmergeMe::splitPairsDeque( void ) {

	std::deque<std::pair<int, int> >::iterator it;

	for (it = this->_pairsDeque.begin(); it != this->_pairsDeque.end(); it++)
		this->_sortedDeque.push_back(it->second);
}

void PmergeMe::findSpotDeque ( std::pair<int,int> pair ) {

	std::deque<int>::iterator upTo = std::find(this->_sortedDeque.begin(), this->_sortedDeque.end(), pair.second);
	std::deque<int>::iterator valuePos = std::lower_bound(this->_sortedDeque.begin(), upTo, pair.first);

	this->_sortedDeque.insert(valuePos, pair.first);
}

void PmergeMe::insertPendingDeque( void ) {

	std::deque<int>::iterator it = this->_sortedDeque.begin();
	this->_sortedDeque.insert(it, this->_pairsDeque[0].first);

	std::deque<std::pair<int, int> >::iterator penValue;
	
	for (penValue = this->_pairsDeque.begin() + 1; penValue != this->_pairsDeque.end(); penValue++)
		findSpotDeque(*penValue);

	if (this->_isEven == false)
	{
		std::deque<int>::iterator valuePos = std::lower_bound(this->_sortedDeque.begin(), this->_sortedDeque.end(), this->_straggler);
		this->_sortedDeque.insert(valuePos, this->_straggler);
	}
	std::cout << "\nAfter : ";
	this->printDeque(this->_sortedDeque);
}

const char* PmergeMe::BadInputException::what( void ) const throw() {

	return ("Error : bad input");
}