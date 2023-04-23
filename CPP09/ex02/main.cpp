#include "PmergeMe.hpp"

/* 
[ 3, 2, 5, 4]
-> [3, 2] [5, 4]

-> [2, 3] [4, 5]

-> 2 < 4 | 3 < 4 | => [2, 3, 4, 5]

- comme philo : avoir une variable start et end,
la différence entre les deux donne le tps d'execution

*/

int main (int ac, char** av ) {

    if (ac < 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }
    
    else 
    {
		try {

        PmergeMe test;

        test.initialiseContainers(ac, av);
		int size = test.getSizeVector();
        // test.insertionSort();
		test.mergeSort(0, size - 1);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
    }
    return 0;
}