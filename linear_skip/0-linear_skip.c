#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer on the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *end;

	if (!list)
		return (NULL);

	node = list;

	/* Parcours via express lane */
	while (node->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       node->express->index, node->express->n);
		if (node->express->n >= value)
			break;
		node = node->express;
	}

	/* Fin de la plage de recherche */
	if (node->express)
		end = node->express;
	else
	{
		end = node;
		while (end->next)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       node->index, end->index);

	/* Recherche linéaire classique entre node et end */
	while (node && node->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}

	return (NULL);
}
