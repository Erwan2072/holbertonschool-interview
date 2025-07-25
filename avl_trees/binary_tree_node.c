#include "binary_trees.h"

/**
 * binary_tree_node - Crée un nouveau nœud
 * @parent: Pointeur vers le parent
 * @value: Valeur à stocker
 * Return: Nouveau nœud
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
