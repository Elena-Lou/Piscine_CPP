#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <vector>

class PmergeMe
{

private:

    std::vector<int> _initial;

public:

    PmergeMe();
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );

    void printVector( void );
    void initialiseContainers( int ac, char** arg );
    void insertionSort( void );

};

#endif