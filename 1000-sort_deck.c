#include "deck.h"
/**
 * cmpfunc - comparaison function.
 * @card1: first card.
 * @card2: second card.
 * Return: difference in value.
 */
int cmpfunc(const card_t *card1, const card_t *card2)
{
	int v1, v2;

	if (!strcmp(card1->value, "Ace"))
		v1 = 1;
	else if (!strcmp(card1->value, "Jack"))
		v1 = 11;
	else if (!strcmp(card1->value, "Queen"))
		v1 = 12;
	else if (!strcmp(card1->value, "King"))
		v1 = 13;
	else
		v1 = atoi(card1->value);
	if (!strcmp(card2->value, "Ace"))
		v2 = 1;
	else if (!strcmp(card2->value, "Jack"))
		v2 = 11;
	else if (!strcmp(card2->value, "Queen"))
		v2 = 12;
	else if (!strcmp(card2->value, "King"))
		v2 = 13;
	else
		v2 = atoi(card2->value);
	if (card1->kind == card2->kind)
		return (v1 - v2);
	return (card1->kind - card2->kind);
}

/**
 * swap_list - swap
 * @list: list
 * @node1: list
 * @node2: list
 * Return: nothing
 */
void swap_list(deck_node_t **list, deck_node_t *node1, deck_node_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	node1->prev = node2, node2->next = node1;
	if (!node2->prev)
		*list = node2;
}
/**
 * cocktail_sort_list - insertion sort algorithm
 * @list: list
 * Return: nothing
 */
void cocktail_sort_list(deck_node_t **list)
{
	deck_node_t *node, *next_n, *prev_n;
	int swpd;

	node = *list;
	do {
		swpd = 0;
		for (; node->next; node = node->next)
		{
			if (cmpfunc(node->card, node->next->card) < 0)
			{
				swpd = 1;
				next_n = node->next;
				swap_list(list, node, next_n);
				node = next_n;
			}
		}
		if (!swpd)
			break;
		for (; node->prev; node = node->prev)
		{
			if (cmpfunc(node->card, node->prev->card) > 0)
			{
				swpd = 1;
				prev_n = node->prev;
				swap_list(list, prev_n, node);
				node = prev_n;
			}
		}
	} while (swpd);
}
/**
 * sort_deck - sort_deck algorithm
 * @deck: list
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || !(*deck)->next)
		return;
	cocktail_sort_list(deck);
}
