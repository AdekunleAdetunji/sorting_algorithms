#include "sort.h"
/**
 * max - a function to find the maximum value in an array
 * @array: The array in question
 * @size: The size of the array
 * Return: The maximum value in the array
 */
int max(int array[], size_t size)
{
	int max_val = array[0];
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] > max_val)
			max_val = array[i];
	return (max_val);
}

/**
 * count_sort - sort an array using the counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 * @den: The value to use in obtaining the array digit place to be sorted
 */
void count_sort(int array[], size_t size, size_t den)
{
	int *temp_arr, count_temp[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++) /* obtain int freq */
		count_temp[(array[i] / den) % 10]++;

	for (i = 1; i < 10; i++) /* obtain cummulative sum */
		count_temp[i] += count_temp[i - 1];

	temp_arr = malloc(sizeof(int) * size); /* allocate memory to temp_arr */
	if (!temp_arr)
		return;

	/* iterate over the array assigning each value to its right idx */
	for (i = size - 1; (int) i >= 0; i--)
	{
		temp_arr[count_temp[(array[i] / den) % 10] - 1] = array[i];
		count_temp[(array[i] / den) % 10] -= 1;
	}

	/* allocate each value of the temp_array to the original array */
	for (i = 0; i < size; i++)
		array[i] = temp_arr[i];

	free(temp_arr);
}

/**
 * radix_sort - sort an array of integers using radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void radix_sort(int *array, size_t size)
{
	int max_val;
	size_t i;

	if (!array || size < 2) /* Check for invalid or one element array */
		return;

	max_val = max(array, size); /* get the maximum value in array */
	/* iterate over the digit places of the maximum value in the array */
	for (i = 1; (max_val / i) > 0; i *= 10)
	{
		count_sort(array, size, i);
		print_array(array, size);
	}
}
