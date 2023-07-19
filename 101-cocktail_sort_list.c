#include "sort.h"

/**
 * cocktail_sort_list - insertion sort algorithm
 * @list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *next_n, *prev_n;
	int swpd;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = *list;
	do {
		swpd = 0;
		for (; node->next; node = node->next)
		{
			if (node->n > node->next->n)
			{
				swpd = 1, next_n = node->next, node->next = next_n->next;
				if (next_n->next)
					next_n->next->prev = node;
				next_n->prev = node->prev;
				if (node->prev)
					node->prev->next = next_n;
				node->prev = next_n, next_n->next = node;
				if (!next_n->prev)
					*list = next_n;
				print_list(*list), node = next_n;
			}
		}
		if (!swpd)
			break;
		for (; node->prev; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				swpd = 1, prev_n = node->prev, prev_n->next = node->next;
				if (node->next)
					node->next->prev = prev_n;
				node->prev = prev_n->prev;
				if (prev_n->prev)
					prev_n->prev->next = node;
				prev_n->prev = node, node->next = prev_n;
				if (!node->prev)
					*list = node;
				print_list(*list), node = prev_n;
			}
		}
	} while (swpd);
}
