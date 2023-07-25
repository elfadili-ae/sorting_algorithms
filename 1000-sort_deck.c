#include "deck.h"


/**
 * cardVal - get the card's value
 * @card: card
 * Return: return the card's value
 */
char cardVal(deck_node_t *card)
{
	if (strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (strcmp(card->card->value, "1") == 0)
		return (1);
	if (strcmp(card->card->value, "2") == 0)
		return (2);
	if (strcmp(card->card->value, "3") == 0)
		return (3);
	if (strcmp(card->card->value, "4") == 0)
		return (4);
	if (strcmp(card->card->value, "5") == 0)
		return (5);
	if (strcmp(card->card->value, "6") == 0)
		return (6);
	if (strcmp(card->card->value, "7") == 0)
		return (7);
	if (strcmp(card->card->value, "8") == 0)
		return (8);
	if (strcmp(card->card->value, "9") == 0)
		return (9);
	if (strcmp(card->card->value, "10") == 0)
		return (10);
	if (strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * swapNode - swap two nodes that are next to each other
 *            in a doubly linked list
 * @this: left node
 * @that: right node
 */
void swapNode(deck_node_t *this, deck_node_t *that)
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

/**
 * sortBackward - sort node going backward of the list
 * @list: doubbly linked list
 * @node: node to sort
 * @k: sort based on kind (1) or value (0)
 */
void sortBackward(deck_node_t **list, deck_node_t *node, int k)
{
	deck_node_t *tmp;

	if (node != NULL && node->prev != NULL)
	{
		if (k && node->card->kind < node->next->card->kind)
		{
			tmp = node->prev;
			swapNode(tmp, node);
			if (node->prev == NULL)
				*list = node;

			if (node->prev != NULL)
				sortBackward(list, node, 1);
		}
		else if (!k
			 && (cardVal(node) < cardVal(node->prev)
			     && node->card->kind == node->prev->card->kind))
		{
			tmp = node->prev;
			swapNode(tmp, node);
			if (node->prev == NULL)
				*list = node;

			if (node->prev != NULL)
				sortBackward(list, node, 0);
		}
		else
			return;
	}
}

/**
 * insertion_sort_list - sort a doubly linked list using
 *   Inertion Sort algorithm
 *
 *@list: doubly linked list
 */
void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *tmp, *prev;

	if (list == NULL || (*list)->next == NULL)
		return;

	tmp = *list;
	while (tmp->next != NULL)
	{
		if (tmp->card->kind > tmp->next->card->kind)
		{
			prev = tmp->next;
			swapNode(tmp, prev);

			if (prev->prev == NULL)
				*list = prev;

			sortBackward(list, prev, 1);
		}
		else
			tmp = tmp->next;
	}

	tmp = *list;
	while (tmp->next != NULL)
	{
		if (cardVal(tmp) > cardVal(tmp->next)
		    && tmp->card->kind == tmp->next->card->kind)
		{
			prev = tmp->next;
			swapNode(tmp, prev);

			if (prev->prev == NULL)
				*list = prev;

			sortBackward(list, prev, 0);
		}
		else
			tmp = tmp->next;
	}
}


/**
 * sort_deck - sort a deck using insertion sort
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || (*deck) == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_list(deck);
}
