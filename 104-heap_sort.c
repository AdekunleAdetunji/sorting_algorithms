#include "sort.h"


void heapify(int array[], size_t lev_idx, size_t size, size_t full_size);


/**
 * heap_sort - sort an array using the heap sort algoritm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t lev, idx;

	if (!array || size < 2)
		return;

	for (lev = (size / 2 - 1); (int) lev > -1; lev--)
		heapify(array, lev, size, size);

	for (idx = size - 1; idx > 0; idx--)
	{
		temp = array[0];
		array[0] = array[idx];
		array[idx] = temp;
		print_array(array, size);
		heapify(array, 0, idx, size);
	}
}

/**
 * heapify - heapify an array to a tree with different levels using recursion
 * such that for each level, the index of the highest level is at the root of
 * that level
 * @array: The array to be heapified
 * @lev_idx: The level within the array to be heapified
 * @size: The size of the array, this is to serve as a base condition for the
 * heapify function
 * @full_size: The full size of the array beign sorted
 */
void heapify(int array[], size_t lev_idx, size_t size, size_t full_size)
{
	int temp;
	size_t root_idx, left_idx, right_idx;

	root_idx = lev_idx;
	left_idx = 2 * lev_idx + 1;
	right_idx = 2 * lev_idx + 2;

	if (left_idx < size && array[left_idx] > array[root_idx])
		root_idx = left_idx;
	if (right_idx < size && array[right_idx] > array[root_idx])
		root_idx = right_idx;

	if (root_idx != lev_idx)
	{
		temp = array[root_idx];
		array[root_idx] = array[lev_idx];
		array[lev_idx] = temp;
		print_array(array, full_size);
		heapify(array, root_idx, size, full_size);
	}
}
