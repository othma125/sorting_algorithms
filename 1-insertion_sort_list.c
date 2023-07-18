#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = (*list)->next;
	while (node)
	{
		for (tmp = list; tmp->next != node; tmp = tmp->next)
		{
			if (tmp->n > node->n)
			{
				node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				print_list(*list);
			}
		}
		node = node->next;
	}
}
