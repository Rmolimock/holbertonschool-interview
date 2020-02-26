#include "binary_trees.h"

/**
 * heap_insert - inserts new node into the heap
 * @root: address of the root node
 * @value: the integer value of the new node
 * Return: address of the new node or NULL on error.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int bit = 0;
	heap_t *node = *root, *new_node;
	ssize_t n = heap_size(*root) + 1;

	new_node = binary_tree_node(node, value);
	if (!new_node)
		return (NULL);
	if (!*root)
		return (*root = new_node);
	for (; 1 << (bit + 1) <= n; bit++)
		;
	for (bit--; bit > 0; bit--)
	{
		if (n & (1 << bit))
			node = node->right;
		else
			node = node->left;
	}
	if (n & 1)
		node->right = new_node;
	else
		node->left = new_node;
	new_node->parent = node;
	return (heapify(new_node));
}

/**
 * heap_size - recursively find the number of nodes in the heap
 * @root: pointer to the root node
 * Return: total number of nodes
 */
size_t heap_size(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * heapify - sorts according to Max Heap
 * @node: starting node
 * Return: pointer to the starting node
 */
heap_t *heapify(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		node->parent->n -= node->n;
		node->n = node->parent->n + node->n;
		node->parent->n = node->n - node->parent->n;
		node = node->parent;
	}
	return (node);
}
