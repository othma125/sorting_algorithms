#include "deck.h"
/**
 * cmpfunc - comparaison function.
 * @c1: first card.
 * @c2: second card.
 * Return: difference in value.
 */
int cmpfunc(const void * c1, const void * c2)
{
	card_t *card1 = (card_t*)c1;
	card_t *card2 = (card_t*)c2;

	if (strcmp(card1->value, card2->value) == 0)
		return (card1->kind - card2->kind);
	return (strcmp(card1->value, card2->value));
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
	deck_node_t *node;
	int swpd;
	node = *list;
	do {
		swpd = 0;
		for (; node->next; node = node->next)
		{
			if (cmpfunc(node, node->next) < 0)
			{
				swpd = 1;
				swap_list(list, node, node->next);
				node = node->next;
			}
		}
		if (!swpd)
			break;
		for (; node->prev; node = node->prev)
		{
			if (cmpfunc(node, node->prev) < 0)
			{
				swpd = 1;
				swap_list(list, node->prev, node);
				node = node->prev;
			}
		}
	} while (swpd);
}
/**
 * sort_deck - sort_deck algorithm
 * @list: list
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || !(deck->next))
		return;
	cocktail_sort_list(deck);
}
