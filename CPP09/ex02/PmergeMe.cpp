#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe( PmergeMe const & src ) {

    *this = src;
}

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs ) {

    if (this != &rhs)
    {

    }
    return *this;
}

PmergeMe::~PmergeMe() {

}
