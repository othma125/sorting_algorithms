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
		for (tmp = node->prev; tmp; tmp = tmp->prev)
		{
			if (tmp->n > node->n
				&& (!tmp->prev || tmp->prev->n <= node->n)
			{
				node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				node->next = tmp;
				if (tmp->prev)
				{
					tmp->prev->next = node;
					node->prev = tmp->prev;
				}
				else
				{
					*list = node;
					node->prev = NULL;
				}
				tmp->prev = node;
				print_list(*list);
				break;
			}
		}
		node = node->next;
	}
}
