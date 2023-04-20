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
void PmergeMe::printVector( void ) {

	for (std::vector<int>::iterator it = _initial.begin(); it != _initial.end(); it++)
    {
       	std::cout << "[" << *it << "] ";
    }
	std::cout << std::endl;
    
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
            // std::cout << "av[" << i << "][" << j << "] : " << arg[i][j] << std::endl;
        }
        value = std::atoi(arg[i]);
        // std::cout << "value = " << value << std::endl;
        this->_initial.push_back(value);
    }
	this->printVector();
}

/* 
Insertion Sort : the array is virtually split into a sorted and unsorted part.
Values from the unsorted part are picked and placed at the correct position in the 
sorted part

This algorithm sorts an array of items by repeatedly taking an element from the unsorted portion of the array and inserting it into its correct position in the sorted portion of the array.

    1. The procedure takes a single argument, ‘A’, which is a list of sortable items.
    2. The variable ‘n’ is assigned the length of the array A.
    3. The outer for loop starts at index ‘1’ and runs for ‘n-1’ iterations, where ‘n’ is the length of the array.
    4. The inner while loop starts at the current index i of the outer for loop and compares each element to its left neighbor. If an element is smaller than its left neighbor, the elements are swapped.
    5. The inner while loop continues to move an element to the left as long as it is smaller than the element to its left.
    6. Once the inner while loop is finished, the element at the current index is in its correct position in the sorted portion of the array.
    7. The outer for loop continues iterating through the array until all elements are in their correct positions and the array is fully sorted.

procedure insertionSort(A: list of sortable items)
   n = length(A)
   for i = 1 to n - 1 do
       j = i
       while j > 0 and A[j-1] > A[j] do
           swap(A[j], A[j-1])
           j = j - 1
       end while
   end for
end procedure
*/

void PmergeMe::insertionSort( void) {
    int initialSize = this->_initial.size();
    
    std::cout << "INSERTION SORT FUNC" << std::endl;
    for (int i = 1; i < initialSize; i++)
    {
        int key = this->_initial[i];
		std::cout << "key = " << key << std::endl;
        int j = i - 1;

        while (j >= 0 && this->_initial[j] > key)
        {
			std::cout << "before swap : [j+1] : " << this->_initial[j+1] << " ; [j] : " << this->_initial[j] << std::endl;
            this->_initial[j + 1] = this->_initial[j];
            j--;
			std::cout << "after swap : [j+1] : " << this->_initial[j+1] << " ; [j] : " << this->_initial[j] << std::endl;

        }
		std::cout << "after loop : [j+1] : " << this->_initial[j+1] << std::endl;
        this->_initial[j + 1] = key;
		std::cout << "after after loop : [j+1] : " << this->_initial[j+1] << std::endl;
		this->printVector();
    }
	std::cout << "END OF FOR LOOP" << std::endl;
	this->printVector();

}
