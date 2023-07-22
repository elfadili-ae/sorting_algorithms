#include "sort.h"

void swapNode(listint_t *this, listint_t *that);

/**
 * cocktail_sort_list - sort a list using cocktail sort algorithm
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	int shuffled = 1;
	listint_t *current = *list, *tmp;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	do {
		shuffled = 0;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				shuffled = 1;
				tmp = current->next;
				swapNode(current, tmp);

				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!shuffled)
			break;
		shuffled = 0;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				shuffled = 1;
				tmp = current->prev;
				swapNode(tmp, current);
				if (current->prev == NULL)
					(*list) = current;

				print_list(*list);
			}
			else
				current = current->prev;
		}
	} while (shuffled);
}

/**
 * swapNode - swap two nodes that are next to each other
 *            in a doubly linked list
 * @this: left node
 * @that: right node
 */
void swapNode(listint_t *this, listint_t *that)
{
	that = this->next;
	this->next = that->next;
	that->next = this;
	that->prev = this->prev;
	this->prev = that;
	if (that->prev)
		that->prev->next = that;
	if (this->next)
		this->next->prev = this;
}
