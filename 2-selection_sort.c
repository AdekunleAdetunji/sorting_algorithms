#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	int temp, temp_2;
	size_t i, j, idx;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		temp = temp_2 = array[i];
		idx = i;
		for (j = i + 1; j < size; j++)
			if (temp_2 > array[j])
			{
				temp_2 = array[j];
				idx = j;
			}
		if (idx != i)
		{
			array[i] = temp_2;
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
