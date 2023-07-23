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
 * bitonic_merge - merges different parts of the array sorted bitonically
 * using the Bitonic merge recursively
 * @arr: array to be sorted
 * @size: total size of the array to be passed into merge for printing
 * @l: lower index to be sorted
 * @count: size or array portion to be sorted at the time
 * @d: direction of sort, ascending: 1, decending: 0
 */
void bitonic_merge(int *arr, unsigned int l, unsigned int count, int d,
				   size_t size)
{
	unsigned int i, k;

	if (count <= 1)
		return;
	k = count / 2;
	for (i = l; i < l + k; i++)
		if (d == (arr[i] > arr[i + k]))
			swap(&arr[i], &arr[i + k]);
	bitonic_merge(arr, l, k, d, size);
	bitonic_merge(arr, l + k, k, d, size);
}
/**
 * bitonic_sorter - sorts an array
 * using the Bitonic sort algorithm recursively
 * @arr: array to be sorted
 * @size: total size of the array to be passed into merge for printing
 * @l: lower index to be sorted
 * @count: size or array portion to be sorted at the time
 * @d: direction of sort, ascending: 1, decending: 0
 */
void bitonic_sorter(int *arr, unsigned int l, unsigned int count, int d,
					size_t size)
{
	int k;
	char *direction = d ? "UP" : "DOWN";

	if (count <= 1)
		return;
	k = count / 2;
	printf("Merging [%u/%lu] (%s):\n", count, size, direction);
	print_array(&arr[l], count);
	bitonic_sorter(arr, l, k, 1, size);
	bitonic_sorter(arr, l + k, k, 0, size);
	bitonic_merge(arr, l, count, d, size);
	printf("Result [%u/%lu] (%s):\n", count, size, direction);
	print_array(&arr[l], count);
}
/**
 * bitonic_sort -  sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sorter(array, 0, size, 1, size);
}
