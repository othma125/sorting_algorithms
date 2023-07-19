#include "sort.h"

/**
 * cocktail_sort_list - insertion sort algorithm
 * @list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *next_node, *prev_node;
	int swpd;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = (*list);
	do {
		swpd = 0;
		for (; node->next; node = node->next)
		{
			if (node->n > node->next->n)
			{
				swpd = 1;
				next_node = node->next;
				node->next = next_node->next;
				node->prev = next_node;
				next_node->prev = node->prev;
				next_node->next = node;
				if (!next_node->prev)
					*list = next_node;
				print_list(*list);
			}
		}
		if (!swpd)
			break;
		for (; node->prev; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				swpd = 1;
				prev_node = node->prev;
				prev_node->next = node->next;
				prev_node->prev = node;
				node->prev = prev_node->prev;
				node->next = prev_node;
				if (!node->prev)
					*list = node;
				print_list(*list);
			}
		}
	} while (swpd);
}
