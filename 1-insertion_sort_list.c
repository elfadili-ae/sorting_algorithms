#include "sort.h"


void sortBackward(listint_t **list, listint_t *node);

/**
 * insertion_sort_list - sort a doubly linked list using
 *   Inertion Sort algorithm
 *
 *@list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *prev;

	if (list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;
	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
		{
			prev = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp->next = prev->next;
			tmp->prev = prev;
			prev->next = tmp;
			if (prev->prev != NULL)
				prev->prev->next =prev;
			else
				*list = prev;

			if (tmp->next != NULL)
				tmp->next->prev = tmp;

			print_list(*list);
			sortBackward(list, prev);
		}
		else
			tmp = tmp->next;
	}
}

 /**
 * sortbackward - sort node going backward of the list
 * @node: node to sort
 */
void sortBackward(listint_t **list, listint_t *node)
{
	listint_t *tmp;

	if (node != NULL && node->prev != NULL)
	{
		if (node->n < node->prev->n)
		{
			tmp = node->prev;
			tmp->next = node->next;
			node->prev = tmp->prev;
			node->next = tmp;
			tmp->prev = node;
			tmp->next->prev = tmp;
			if (node->prev != NULL)
				node->prev->next = node;
			else
				*list = node;
			print_list(*list);
			if (node->prev != NULL)
				sortBackward(list, node);
		}
		else
			return;
	}
	return;
}
