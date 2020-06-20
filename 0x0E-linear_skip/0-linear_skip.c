#include "search.h"

/**
 * ls - perform a linear search through linked list
 * @prev: starting node
 * @exp: ending node
 * @value: value being searched for
 * Return: Node with value upon success, else None
 */
skiplist_t *helper(skiplist_t *prev, skiplist_t *exp, int value)
{
	printf("Value found between indexes [%li] and [%li]\n",
			prev->index, exp->index);
	while (prev != exp->next)
	{
		printf("Value checked at index [%li] = [%i]\n",
				prev->index, prev->n);
		if (value == prev->n)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

/**
 * linear_skip -  find value in a sorted skip list
 * @list: list being searched
 * @value: value being searched for
 * Return: node with value else None
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *exp;

	if (!list)
		return (NULL);
	exp = list;
	while (exp)
	{
		prev = exp;
		if (!(exp->express)) {
            while (exp->next)
				exp = exp->next;
			break;
        }
		else
			exp = exp->express;
		printf("Value checked at index [%li] = [%i]\n", exp->index, exp->n);
		if (exp->n >= value)
			return (helper(prev, exp, value));
	}
	return (helper(prev, exp, value));
}