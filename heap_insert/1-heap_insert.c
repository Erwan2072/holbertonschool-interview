#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current;

    if (!root)
        return (NULL);

    /* Create a new node */
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root) /* If tree is empty, new node becomes root */
    {
        *root = new_node;
        return (new_node);
    }

    /* Insert node in level-order */
    current = *root;
    while (current)
    {
        if (!current->left) /* Insert at left if available */
        {
            current->left = new_node;
            new_node->parent = current;
            break;
        }
        else if (!current->right) /* Insert at right if available */
        {
            current->right = new_node;
            new_node->parent = current;
            break;
        }

        /* Traverse left or right (implement level-order logic) */
        if (current->left)
            current = current->left;
        else
            current = current->right;
    }

    /* Fix heap property */
    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        int temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;
        new_node = new_node->parent;
    }

    return (new_node);
}
