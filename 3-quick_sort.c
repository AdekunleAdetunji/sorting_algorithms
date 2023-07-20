#include "sort.h"
/**
 * swap - swaps 2 elements in address locks
 * @a: address of a
 * @b: address of b
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - partitions an array using the lumoto algorithm
 * @arr: array to partition
 * @l: index of lower bound of array
 * @h: index of high bound
 * @size: size of the array
 * Return: index of partition
 */
int partition(int arr[], int l, int h, size_t size)
{
	int i, pivot = arr[h], g = l - 1;
	/**
	 * g is index of the value greater than pivot
	 *  start from out of arr
	 */

	for (i = l; i < h; i++) /*loop from low bound to high - 1*/
	{
		if (arr[i] < pivot)
		{
			g++; /*g will be increased into the bounds of the array*/
			if (arr[g] != arr[i])
			{
				swap(&arr[g], &arr[i]);
				print_array(arr, size);
			}
		}
	}
	/**
	 * after the loop, the elements will have been splited in 2
	 * one side less than the pivot, the other greater
	 */
	g++;
	if (arr[g] != pivot)
	{
		/*arr[h] is brought to the partitioned position*/
		swap(&arr[g], &arr[h]);
		print_array(arr, size);
	}
	return (g);
}

/**
 * sort - sorts using quick sort algorithm
 * @arr: array to sort
 * @l: index of lower bound
 * @h: index of higher bound
 * @size: size of the array
 */
void sort(int arr[], int l, int h, size_t size)
{
	int p;

	if (l >= h)
		return;
	/*get the partition*/
	p = partition(arr, l, h, size);
	/*sort the left side recursively*/
	sort(arr, l, p - 1, size);
	/*sort the right side recursively*/
	sort(arr, p + 1, h, size);
}
/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
