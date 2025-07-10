#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Get the maximum value in the array
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum integer
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort - Performs counting sort based on digit represented by exp
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Exponent (digit position)
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output, count[10] = {0};
    size_t i;

    output = malloc(size * sizeof(int));
    if (!output)
        return;

    /* Count occurrences of digits */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Update count[i] so it contains actual position of this digit in output[] */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build output array (stable sort) */
    for (i = size; i > 0; i--)
    {
        output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / exp) % 10]--;
    }

    /* Copy sorted data back to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);

    print_array(array, size);
}

/**
 * radix_sort - Main LSD Radix Sort function
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (!array || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort(array, size, exp);
}
