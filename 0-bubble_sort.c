#include "sort.h"

/**
 * bubble_sort - Sorts an array of int in ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function implements the Bubble Sort algorithm to sort
 *              the given array of integers in ascending order. It iterates
 *              through the array multiple times, comparing adjacent elements
 *              and swapping them if they are in the wrong order, until the
 *              entire array is sorted.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
