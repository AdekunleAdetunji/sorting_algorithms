#include "sort.h"
/**
 * shell_sort -  sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap, i, j; /*i for outer loop, j for inner loop*/
	int toSwap;

	/*first get the value of gap with knth sequence*/
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;
	for (; gap > 0; gap /= 3) /*loop decrements gap*/
	{
		for (i = gap; i < size; i++) /*outer loop*/
		{
			toSwap = array[i];
			/*inner loop sorts each interval with insertion sort*/
			for (j = i; j > gap - 1 && array[j - gap] > toSwap; j -= gap)
				array[j] = array[j - gap];
			array[j] = toSwap;
		}
		print_array(array, size);
	}
}
