#include "sort.h"


/**
 * swap_list - swap
 * @list: list
 * @node1: list
 * @node2: list
 * Return: nothing
 */
void swap_list(listint_t **list, listint_t *node1, listint_t *node2)
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
	print_list(*list);
}
/**
 * cocktail_sort_list - insertion sort algorithm
 * @list: list
 * Return: nothing
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
			if (node->n < node->prev->n)
			{
				swpd = 1;
				prev_n = node->prev;
				swap_list(list, prev_n, node);
				node = prev_n;
			}
		}
	} while (swpd);
}
