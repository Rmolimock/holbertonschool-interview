#include "binary_trees.h"

/**
 * avl - recursive helper function to increase num of parameters available
 * @parent: parent of the current node
 * @array: array to be converted
 * @position: position of the (sometimes sub) array
 * @end: end of the array
 * Return: new node
 */
avl_t *avl(avl_t *parent, int *array, int position, int end)
{
	avl_t *new;
	int half;

	if (position > end)
		return (NULL);
	half = (position + end) / 2;
	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);
	new->n = array[half];
	new->parent = parent;
	new->left = avl(new, array, position, half - 1);
	new->right = avl(new, array, half + 1, end);
	return (new);
}

/**
 * sorted_array_to_avl - convert a sorted array into an AVL tree
 * @array: array to be sorted
 * @size: size of the array
 * Return: head of the tree on success, else NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (!array)
		return (NULL);
	return (avl(NULL, array, 0, size - 1));
}