#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <utility>

class PmergeMe
{

private:

    std::vector<int> _argVector;
    std::vector<std::pair<int, int> > _pairsVector;
	std::vector<int> _sortedVector;
	int*			 _jacobSequence;
    int             _straggler;
    bool            _isEven;

public:

    PmergeMe();
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );

    int     getStraggler( void ) const;
    bool    isEven( void );
    void    printVector( void );
    void    printVector( std::vector<int> vector );
    void    printPairsVector( void );
    int     getSize( void ) const;
    int     jacobsthal( int n );

    void    initialiseContainers( int ac, char** arg );
    void    divideIntoPairs( void );
    void    sortEachPair( void );
    void    recursivelySortPairs( int n );
    void    splitPairs( void );
	void	insertPending( void );
	void	buildJacobSequence( void );
	void	findSpot( std::pair<int,int> pair );

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