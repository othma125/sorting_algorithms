#include "sort.h"
#include <limits.h>

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int aux = *a;

	*a = *b;
	*b = aux;
}
/**
 * selection_sort - selection_sort algorithm
 * @array: int array
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_j;
	int *ptr = array, min;

	if (!array || size < 2)
		return;
	while (i < size)
	{
		min = INT_MAX;
		min_j = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
				min = array[j], min_j = j;
		}
		if (i < min_j)
		{
			swap(ptr, array + min_j);
			print_array(array, size);
		}
		i++;
		ptr++;
	}
}
