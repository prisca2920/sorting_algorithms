#include "sort.h"

/**
 * _swaps - swaps two ints
 * @node: node to check
 * @list: the list to check
 */

void _swaps(listint_t **node, listint_t **list)
{
	listint_t *head = *node;
	listint_t *temp, *curr;

	if ((*node)->prev == NULL)
	{
	*list = (*node)->next;
	}

	temp = head->next;

	head->next = temp->next;

	curr = head->prev;

	head->prev = temp;

	temp->next = head;

	temp->prev = curr;

	if (temp->prev != NULL)
	{
	temp->prev->next = temp;
	}

	if (head->next != NULL)
	{
	head->next->prev = head;
	}

	*node = temp;
}


/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: the doubly linked list to be sorted
 * Return: the sorted list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL)
	{
	return;
	}

	curr = *list;

	while (curr && curr->next)
	{
	if (curr->n > curr->next->n)
	{
	_swaps(&curr, list);

	print_list(*list);

	while (curr && curr->prev)
	{
	if (curr->n < (curr->prev)->n)
	{
	curr = curr->prev;

	_swaps(&curr, list);

	print_list(*list);

	curr = curr->next;
	}
	curr = curr->prev;
	}
	}
	curr = curr->next;
	}
}
