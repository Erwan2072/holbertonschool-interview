#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merge two sorted subarrays into original array
 * @array: The original array
 * @left: Left subarray
 * @right: Right subarray
 * @left_size: Size of left
 * @right_size: Size of right
 */
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }
    while (i < left_size)
        array[k++] = left[i++];
    while (j < right_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    print_array(array, left_size + right_size);
}

/**
 * merge_sort_recursive - Recursive part of merge sort
 * @array: The array to sort
 * @size: Size of the array
 * @buffer: Temporary buffer (only one malloc)
 */
void merge_sort_recursive(int *array, size_t size, int *buffer)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    size_t i;

    for (i = 0; i < mid; i++)
        buffer[i] = array[i];
    for (; i < size; i++)
        buffer[i] = array[i];

    merge_sort_recursive(buffer, mid, array);
    merge_sort_recursive(buffer + mid, size - mid, array + mid);

    merge(array, buffer, buffer + mid, mid, size - mid);
}

/**
 * merge_sort - Entry point
 * @array: The array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int *buffer = malloc(sizeof(int) * size);
    if (!buffer)
        return;

    merge_sort_recursive(array, size, buffer);
    free(buffer);
}
