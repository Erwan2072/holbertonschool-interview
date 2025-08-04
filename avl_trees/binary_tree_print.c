#include "binary_trees.h"
#include <string.h> /* Pour memset, memcpy, strlen */

/* Constants */
#define MAX_HEIGHT 1000
#define BUFFER_SIZE 255

static int _height(const binary_tree_t *tree);
static int _max(int a, int b);
static void _print(const binary_tree_t *tree, int is_left, int offset, int depth, char **s);

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char *s[MAX_HEIGHT];
    int i, height, width = 255;

    if (!tree)
        return;

    height = _height(tree);
    for (i = 0; i < MAX_HEIGHT; i++)
    {
        s[i] = malloc(width);
        if (!s[i])
            return;
        memset(s[i], ' ', width - 1);
        s[i][width - 1] = '\0';
    }

    _print(tree, 0, 0, 0, s);

    for (i = 0; i < height && s[i][0] != '\0'; i++)
    {
        printf("%s\n", s[i]);
        free(s[i]);
    }
}

/**
 * _height - Computes the height of a binary tree
 * @tree: Tree to measure
 * Return: Height
 */
static int _height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + _max(_height(tree->left), _height(tree->right)));
}

/**
 * _max - Return the max of 2 integers
 */
static int _max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * _print - Fills an array of strings to represent the tree
 */
static void _print(const binary_tree_t *tree, __attribute__((unused)) int is_left, int offset, int depth, char **s)
{
    char b[BUFFER_SIZE];
    int width;

    if (!tree)
        return;

    sprintf(b, "(%03d)", tree->n);
    width = strlen(b);

    _print(tree->left, 1, offset, depth + 1, s);
    memcpy(s[depth] + offset, b, width);
    _print(tree->right, 0, offset + width + 1, depth + 1, s);
}

