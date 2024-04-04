#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * @array: Pointer to the array to be sorted.
 * @l: Index of the left subarray.
 * @m: Index of the middle element.
 * @r: Index of the right subarray.
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
    int *L, *R;

    /* Create temporary arrays */
    L = malloc(n1 * sizeof(int));
    R = malloc(n2 * sizeof(int));
    if (L == NULL || R == NULL)
    {
        free(L);
        free(R);
        return;
    }

    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    /* Merge the temporary arrays back into array[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if any */
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if any */
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    /* Free temporary arrays */
    free(L);
    free(R);
}

/**
 * merge_sort_recursive - Main function for merge sort.
 * @array: Pointer to the array to be sorted.
 * @l: Index of the leftmost element.
 * @r: Index of the rightmost element.
 */
void merge_sort_recursive(int *array, size_t l, size_t r)
{
    if (l < r)
    {
        /* Same as (l+r)/2, but avoids overflow for large l and r */
        size_t m = l + (r - l) / 2;

        /* Sort first and second halves */
        merge_sort_recursive(array, l, m);
        merge_sort_recursive(array, m + 1, r);

        /* Merge the sorted halves */
        merge(array, l, m, r);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    printf("Merging...\n");
    merge_sort_recursive(array, 0, size - 1);
}
