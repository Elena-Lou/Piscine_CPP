#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <exception>

class PmergeMe
{

private:

    std::vector<int> _initial;

public:

    PmergeMe();
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );

    int getSizeVector( void );

    void printVector( void );
    void initialiseContainers( int ac, char** arg );
    void insertionSort( void );
    void mergeSort( int begin, int end );
    void merge(int begin, int mid, int end );

    class BadInputException : public std::exception
    {
        public:

            const char* what( void ) const throw();
    };


};

#endif