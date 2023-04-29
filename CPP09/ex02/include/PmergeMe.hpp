#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <algorithm>
#include <utility>
#include <time.h>
#include <iomanip>

class PmergeMe
{

private:

    std::vector<int>					_argVector;
    std::vector<std::pair<int, int> >	_pairsVector;
	std::vector<int>					_sortedVector;

	std::deque<int>						_argDeque;
	std::deque<std::pair<int, int> >	_pairsDeque;
	std::deque<int>						_sortedDeque;
	
    int									_straggler;
    bool								_isEven;
	int									_size;
	
public:

    PmergeMe();
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );

    bool    isEvenVector( void );
    void    printVector( std::vector<int> vector );
    void    printPairsVector( void );
	void	sortVector(int ac, char** arg );
    void    initialiseVector( int ac, char** arg );
    void    divideIntoPairsVector( void );
    void    sortEachPairVector( void );
    void    recursivelySortPairsVector( int n );
    void    splitPairsVector( void );
	void	insertPendingVector( void );
	void	findSpotVector( std::pair<int,int> pair );

	bool    isEvenDeque( void );
    void    printDeque( std::deque<int> deque );
    void    printPairsDeque( void );
	void	sortDeque(int ac, char** arg );
    void    initialiseDeque( int ac, char** arg );
    void    divideIntoPairsDeque( void );
    void    sortEachPairDeque( void );
    void    recursivelySortPairsDeque( int n );
    void    splitPairsDeque( void );
	void	insertPendingDeque( void );
	void	findSpotDeque( std::pair<int,int> pair );

    void    insertionSort( void );
    void    mergeSort( int begin, int end );
    void    merge(int begin, int mid, int end );

    class BadInputException : public std::exception
    {
        public:

            const char* what( void ) const throw();
    };


};

#endif