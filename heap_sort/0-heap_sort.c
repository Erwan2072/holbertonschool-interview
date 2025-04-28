#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in an array
 *
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Heapifies a subtree with the root at index `i`
 *
 * @array: Array to be heapified
 * @size: Size of the array
 * @i: Root index of the subtree
 */
void sift_down(int *array, size_t size, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        sift_down(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i != (size_t)-1; i--)
        sift_down(array, size, i);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, i, 0);
    }
}
