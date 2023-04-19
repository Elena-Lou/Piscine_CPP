#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include <iostream>

class PmergeMe
{

private:

public:

    PmergeMe();
    PmergeMe( PmergeMe const & src );
    ~PmergeMe();

    PmergeMe & operator=( PmergeMe const & rhs );

};

#endif