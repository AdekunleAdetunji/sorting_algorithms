#include "sort.h"
#include <stdio.h>
/**
 * find_max - get max value of array
 * @arr: array
 * @size: size
 */
int find_max(int *arr, size_t size)
{
    int max = arr[0];
    unsigned int i;

    for (i = 1; i < size; i++)
        max = arr[i] > max ? arr[i] : max;
    return max;
}
/**
 * counting_sort_adjusted - sorts an array of integers in ascending order
 * using the Counting sort algorithm, reduces space used
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort_adjusted(int *array, size_t size)
{
    unsigned int *count, k, i, j;

    if (!array || size < 2)
        return;

    k = find_max(array, size);
    printf("%d\n", k);
    count = malloc(sizeof(int) * k + 1);
    for (i = 0; i < k + 1; i++)
        count[i] = 0;
    for (i = 0; i < size; i++)
    {
        j = array[i];
        count[j]++;
    }
    for (i = 0, j = 0; i < k + 1; i++)
    {
        while (count[i]--)
        {
            array[j++] = i;
        }
    }
    free(count);
}