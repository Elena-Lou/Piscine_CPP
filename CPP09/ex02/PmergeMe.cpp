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
				throw PmergeMe::BadInputException();
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

int PmergeMe::getSizeVector( void ) {

	return this->_initial.size();
}

/*
	Divide and Conquer Strategy: 

Using the Divide and Conquer technique, we divide a problem into subproblems. 
When the solution to each subproblem is ready, we 'combine' the results from the subproblems to solve the main problem.

Suppose we had to sort an array A. 
A subproblem would be to sort a sub-section of this array starting at index p and ending at index r, denoted as A[p..r].

Divide

If q is the half-way point between p and r, then we can split the subarray A[p..r] into two arrays A[p..q] and A[q+1, r].

Conquer

In the conquer step, we try to sort both the subarrays A[p..q] and A[q+1, r]. 
If we haven't yet reached the base case, we again divide both these subarrays and try to sort them.

Combine

When the conquer step reaches the base step and we get two sorted subarrays A[p..q] and A[q+1, r] for array A[p..r], 
we combine the results by creating a sorted array A[p..r] from two sorted subarrays A[p..q] and A[q+1, r].
 --- 

The MergeSort function repeatedly divides the array into two halves until 
we reach a stage where we try to perform MergeSort on a subarray of size 1 i.e. p == r.

After that, the merge function comes into play and combines
 the sorted arrays into larger arrays until the whole array is merged.

MergeSort(A, p, r):
    if p > r 
        return
    q = (p+r)/2
    mergeSort(A, p, q)
    mergeSort(A, q+1, r)
    merge(A, p, q, r)

To sort an entire array, we need to call 
 MergeSort(A, 0, length(A)-1).

The merge sort algorithm recursively divides the array into halves until
we reach the base case of array with 1 element. 
After that, the merge function picks up the sorted sub-arrays and
 merges them to gradually sort the entire array.

Have we reached the end of any of the arrays?
    No:
        Compare current elements of both arrays 
        Copy smaller element into sorted array
        Move pointer of element containing smaller element
    Yes:
        Copy all remaining elements of non-empty array

*/

// Merge two subvectors L and M into the initial one
void PmergeMe::merge(int begin, int mid, int end ) {

	std::cout << "MERGE FUNCTION" << std::endl;
	int n1 = mid - begin + 1;
	int n2 = end - mid;	
	std::cout << "n1 : " << n1 << " - n2 : " << n2 << std::endl;

	std::vector<int> L(n1), R(n2);
	std::cout << "L.size() : " << L.size() << " - R.size() : " << R.size() << std::endl;

	for (int i = 0; i < n1; i++)
		L[i] = this->_initial[begin + i];
	for (int j = 0; j < n2; j++)
		R[j] = this->_initial[mid + 1 + j];

	int i, j, k;
	i = 0;
	j = 0;
	k = begin;
	std::cout << "k : " << k << std::endl;

 // Until we reach either end of either L or R, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			this->_initial[k] = L[i];
			i++;
		}
		else
		{
			this->_initial[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		this->_initial[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		this->_initial[k] = R[j];
		j++;
		k++;
	}

}


void PmergeMe::mergeSort( int begin, int end ) {

	std::cout << "MERGE SORT FUNCTION" << std::endl;
	std::cout << "begin : " << begin << " - end : " << end << std::endl;

	if (begin < end)
	{
		int mid; //the point where the vector is divided into two subvectors
		mid = begin + (end - begin) / 2;

		this->mergeSort(begin, mid);
		this->mergeSort(mid + 1, end);

		this->merge(begin, mid, end);

	}
	this->printVector();
}

const char* PmergeMe::BadInputException::what( void ) const throw() {

	return ("Error : bad input");
}