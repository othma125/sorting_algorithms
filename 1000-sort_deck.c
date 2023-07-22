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
 * sort_deck - sort_deck algorithm
 * @list: list
 */
void sort_deck(deck_node_t **deck)
{
}
