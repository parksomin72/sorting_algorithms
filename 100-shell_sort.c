#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	    int interval;
	int i;

    if (array == NULL || size < 2)
        return;


    interval = 1;
    while (interval < (int)size / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        for (i = interval; i < (int)size; i++)
        {
            int temp = array[i];
            int j;

            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
        print_array(array, size);
        interval = (interval - 1) / 3;
    }
}
