#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (!list || !*list || !list->next)
		return;
	node = *list;
	while (node)
	{
		for (i = 0; i + 1 < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
			}
		}
		node = node->next;
	}
}
