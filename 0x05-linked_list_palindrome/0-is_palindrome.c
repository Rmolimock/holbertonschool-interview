#include <stdlib.h>
#include "lists.h"

/**
 *is_palindrome - check if given linked list constitutes a palindrome
 *@head: double pointer to the head of the list
 *
 *Return: 1 if palindrome, otherwise 0.
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int *original;
	size_t size = 0;
	size_t i = 0;

	if (head == NULL || *head == NULL)
		return (1);
	current = *head;
	while (current)
	{
		current = current->next;
		size += 1;
	}
	original = malloc(sizeof(int) * size);
	if (!original)
		return (0);
	current = *head;
	while (current)
	{
		original[i] = current->n;
		current = current->next;
		i++;
	}
	for (i = 0; i <= size; i++, size--)
	{
		if (original[i] != original[size - 1])
			return (0);
	}
	return (1);
}
