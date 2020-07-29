#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list
 * @head: head of the list
 * Return: start of the loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = slow;

	if (!head || !head->next)
		return (NULL);
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			slow = head;
			while (slow != fast)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return (slow);
		}
	}
	return (NULL);
}