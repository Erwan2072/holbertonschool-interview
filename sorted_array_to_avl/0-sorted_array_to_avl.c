#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl - Recursively builds AVL tree from sorted array
 * @array: Array of ints
 * @start: Start index
 * @end: End index
 * @parent: Parent node
 * Return: Root node
 */
avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;
    avl_t *root = binary_tree_node(parent, array[mid]);
    if (!root)
        return (NULL);

    root->left = create_avl(array, start, mid - 1, root);
    root->right = create_avl(array, mid + 1, end, root);
    return (root);
}

/**
 * sorted_array_to_avl - Creates AVL tree from sorted array
 * @array: Pointer to array
 * @size: Number of elements
 * Return: Root node of AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);
    return (create_avl(array, 0, (int)size - 1, NULL));
}
