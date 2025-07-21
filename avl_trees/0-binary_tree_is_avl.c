#include "binary_trees.h"
#include <limits.h>

/**
 * height - Calcule la hauteur d’un arbre binaire
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int left_h = height(tree->left);
	int right_h = height(tree->right);

	return (1 + (left_h > right_h ? left_h : right_h));
}

/**
 * is_bst - Vérifie que l’arbre est un BST valide
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
	        is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Vérifie récursivement que l’arbre respecte les propriétés AVL
 */
int is_avl_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	int left_h = height(tree->left);
	int right_h = height(tree->right);
	int balance = left_h - right_h;

	if (balance < -1 || balance > 1)
		return (0);

	return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Vérifie si l’arbre est un AVL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl_helper(tree));
}
