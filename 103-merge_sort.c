#include "sort.h"
/**
 * merge - merges splitted array into the original,
 * @a: original
 * @b: duplicate
 * @start: start index
 * @middle: middle of array
 * @end: end of array
 */
void merge(int *a, int *b, unsigned int start, unsigned int middle,
		   unsigned int end)
{

	unsigned int i, j, k;

	i = start;
	j = middle;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(&b[start], middle - start);
	printf("[right]: ");
	print_array(&b[middle], end - middle);
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || b[i] <= b[j]))
			a[k] = b[i++];
		else
			a[k] = b[j++];
	}
	printf("[Done]: ");
	print_array(&a[start], end - start);
}
/**
 * split_n_merge - splits the duplicate,
 * sorts it and merges it into the original
 * @a: original
 * @b: duplicate
 * @start: start index
 * @end: end of array
 */
void split_n_merge(int *a, int *b, unsigned int start, unsigned int end)
{
	unsigned int middle;

	if (end - start <= 1)
		return;

	middle = (end + start) / 2;
	split_n_merge(b, a, start, middle);
	split_n_merge(b, a, middle, end);
	merge(a, b, start, middle, end);
}
/**
 * merge_sort - ssorts an array of integers in ascending order
 * using the topdown Merge sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *dup;
	unsigned int i;

	if (!array || size < 2)
		return;
	dup = malloc(sizeof(int) * size);
	if (!dup)
		return;
	for (i = 0; i < size; i++)
		dup[i] = array[i];
	split_n_merge(array, dup, 0, size);
	free(dup);
}
