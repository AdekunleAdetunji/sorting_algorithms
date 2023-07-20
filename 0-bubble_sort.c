#include "sort.h"

/**
 * bubble_sort - sort an array using the bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int flag, temp;
	size_t i, j;

	for (i = size; i > 0; i--)
	{
		flag = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
