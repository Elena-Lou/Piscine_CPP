#include "PmergeMe.hpp"

/* 
    1. determine size on the sequence : if odd numbered, set aside the last element 
    in a "straggler variable" => DONE

    2. divide the sequence into pairs of two values  => DONE

    3. sort each pair bitwise [less, greater] => DONE

    4. sort the sequence recursively by the value of the largest pair

    5. create a new final vector and initiate it with the highest values of each pair

    6. the remaining values are set aside in a pending vector

    7. use Jacobsthal numbers to insert the values from pending to final 
    (first insert the first one at index 0, then pending[3], pending[2], pending[5], pending[4]... )
    /!\ to check that the nextOp is not greater than the size of the array
    + operate from the nextOp (index) to the lastOp (index) by decrementing the value of the index

    8. if a straggler was set aside, insert it last in the final vector 

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

        // test.insertionSort();
		// test.mergeSort(0, size - 1);

		std::cout << std::boolalpha << test.isEven() << std::endl;
		// std::cout << test.getStraggler() << std::endl;
		test.divideIntoPairs();
		test.sortEachPair();
        int size = test.getSize();
        test.recursivelySortPairs(size);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
    }
    return 0;
}