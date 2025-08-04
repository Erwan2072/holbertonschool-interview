#include "binary_trees.h"
#include <limits.h>

/**
 * height - Calcule la hauteur d’un arbre binaire
 * @tree: Pointeur vers la racine de l’arbre
 * Return: Hauteur de l’arbre
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	    int left = height(tree->left);
	    int right = height(tree->right);
	return (1 + (left > right ? left : right));
}


/**
 * is_bst - Vérifie que l’arbre est un BST valide
 * @tree: Pointeur vers la racine
 * @min: Valeur minimale autorisée
 * @max: Valeur maximale autorisée
 * Return: 1 si c'est un BST, 0 sinon
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
 * is_avl_helper - Vérifie récursivement
 * @tree: Pointeur vers la racine
 * Return: 1 si l’arbre est un AVL, 0 sinon
 */
int is_avl_helper(const binary_tree_t *tree)
{
	int lh, rh, balance;

	if (!tree)
		return (1);

	lh = height(tree->left);
	rh = height(tree->right);
	balance = lh - rh;

	if (balance < -1 || balance > 1)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX) &&
		is_avl_helper(tree->left) &&
		is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Vérifie si un arbre est un AVL valide
 * @tree: Pointeur vers la racine de l’arbre
 * Return: 1 si AVL, 0 sinon
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl_helper(tree));
}
