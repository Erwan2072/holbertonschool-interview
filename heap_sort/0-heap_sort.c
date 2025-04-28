#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Performs the sift-down operation on a heap
 * @array: The array representing the heap
 * @size: Size of the array/heap
 * @base: The base index where sift-down starts
 * @root: The current root index of the subtree to sift-down
 */
void sift_down(int *array, size_t size, size_t base, size_t root)
{
    size_t largest, left, right;

    largest = root;
    left = 2 * root + 1;
    right = 2 * root + 2;

    /* Compare root with left child */
    if (left < base && array[left] > array[largest])
        largest = left;

    /* Compare largest with right child */
    if (right < base && array[right] > array[largest])
        largest = right;

    /* If root is not the largest, swap and continue sifting down */
    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, size);
        sift_down(array, size, base, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Description: Implements the sift-down heap sort algorithm
 * and prints the array after each swap
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Build max heap */
    for (i = size / 2; i > 0; i--)
        sift_down(array, size, size, i - 1);

    /* Extract root and rebuild heap */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, size, i, 0);
    }
}
