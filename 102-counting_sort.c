#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array;
    int *output;
    int max = array[0];
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array */
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Allocate memory for the counting array */
    count_array = malloc((max + 1) * sizeof(int));
    if (count_array == NULL)
        return;

    /* Initialize counting array elements to zero */
    for (i = 0; i <= (size_t)max; i++)
        count_array[i] = 0;

    /* Store count of each element in the input array */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the counting array */
    printf("%d", count_array[0]);
    for (i = 1; i <= (size_t)max; i++)
        printf(", %d", count_array[i]);
    printf("\n");

    /* Modify the count array such that each element stores the
     * position of the element in the output array */
    for (i = 1; i <= (size_t)max; i++)
        count_array[i] += count_array[i - 1];

    /* Build the output array */
output = malloc(size * sizeof(int));
if (output == NULL)
{
    free(count_array);
    return;
}

for (i = size; i > 0; i--)
{
    output[count_array[array[i - 1]] - 1] = array[i - 1];
    count_array[array[i - 1]]--;
}

    /* Copy the output array to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free dynamically allocated memory */
    free(count_array);
    free(output);
}
