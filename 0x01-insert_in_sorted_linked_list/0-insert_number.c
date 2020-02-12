#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert - insert node at start of list
 * @head: pointer to head of list
 * @n: value of the new node
 *
 * Return: pointer to new node
 */

listint_t *insert(listint_t **head, const int n)
{
	listint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * insert_node - insert node into sorted linked list
 * @head: pointer to the head of the list
 * @number: value of the new node
 *
 * Return: pointer to new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t *current = NULL;

	if (!head)
		return (NULL);
	if (!*head)
	{
		new = insert(head, number);
		return (new);
	}
	if (!(*head)->next)
	{
		if ((*head)->n > number)
		{
			new = insert(head, number);
			return (new);
		}
		add_nodeint_end(head, number);
	}
	current = *head;
	if ((*head)->n > number)
	{
		new = insert(head, number);
		return (new);
	}
	while (current->next)
	{
		if (current->next->n > number)
			break;
		current = current->next;
	}
	new = malloc(sizeof(listint_t *));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = current->next;
	current->next = new;
	return (new);
}
