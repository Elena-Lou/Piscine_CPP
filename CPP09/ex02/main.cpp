#include "PmergeMe.hpp"

int main (int ac, char** av ) {

    if (ac < 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }
    
    else if (ac == 2)
    {
        std::cout << "sorted sequence : " << av[1] << std::endl;
        return 0;
    }

    else 
    {
        PmergeMe test;

        test.initialiseContainers(ac, av);
        test.insertionSort();
    }
    return 0;
}