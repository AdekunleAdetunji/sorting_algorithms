#include "sort.h"
#include <stdio.h>
/**
 * find_max - get max value of array
 * @arr: array
 * @size: size
 * Return: max value
 */
int find_max(int *arr, size_t size)
{
	int max = arr[0];
	unsigned int i;

	for (i = 1; i < size; i++)
		max = arr[i] > max ? arr[i] : max;
	return (max);
}
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	unsigned int *count, *sorted, k, i, j;

	if (!array || size < 2)
		return;
	k = find_max(array, size);
	count = malloc(sizeof(int) * k + 1);
	if (!count)
		return;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(count);
		return;
	}
	for (i = 0; i < k + 1; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		j = array[i];
		count[j]++;
	}
	for (i = 1; i < k + 1; i++)
		count[i] = count[i] + count[i - 1];
	print_array((int *)count, k + 1);
	for (i = 0; i < size; i++)
	{
		j = array[i];
		sorted[--count[j]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(count);
}
