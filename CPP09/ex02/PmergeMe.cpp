#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _initial(0) {

}

PmergeMe::PmergeMe( PmergeMe const & src ) : _initial(src._initial) {

    *this = src;
}

PmergeMe & PmergeMe::operator=( PmergeMe const & rhs ) {

    if (this != &rhs)
    {
        this->_initial = rhs._initial;
    }
    return *this;
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::initialiseContainers( int ac, char** arg ) {

    std::cout << "INIT CONTAINERS" << std::endl;
    int value;

    for (int i = 1; i < ac; i++)
    {
        for (size_t j = 0; j < std::strlen(arg[i]); j++)
        {
            if (!std::isdigit(arg[i][j]))
            {
                std::cerr << "wrong argument" << std::endl;
                return ;
            }
            std::cout << "av[" << i << "][" << j << "] : " << arg[i][j] << std::endl;
        }
        value = std::atoi(arg[i]);
        std::cout << "value = " << value << std::endl;
        this->_initial.push_back(value);
    }
    
    for (std::vector<int>::iterator it = _initial.begin(); it != _initial.end(); it++)
    {
        std::cout << "[" << *it << "] ";
    }
    
}
