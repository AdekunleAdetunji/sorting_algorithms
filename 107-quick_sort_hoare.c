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
	int i, j, pivot = arr[h];

	i = l - 1;
	j = h + 1;
	while (i < j)
	{
		do
			i++;
		while (arr[i] < pivot);
		do
			j--;
		while (arr[j] > pivot);
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}
	return (i);
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

	if (l < 0 || h < 0 || l >= h)
		return;
	/*get the partition*/
	p = partition(arr, l, h, size);
	/*sort the left side recursively*/
	sort(arr, l, p - 1, size);
	/*sort the right side recursively*/
	sort(arr, p, h, size);
}
/**
 * quick_sort_hoare -  sorts an array of integers in ascending order
 * using the Quick sort algorithm with hoare's partition aldorithm
 * @array: array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
