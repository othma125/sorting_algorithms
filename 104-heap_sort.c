#include "sort.h"

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
 * heap_sort - heap_sort algorithm
 * @array: int array
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	size_t n = size, i;

	if (!array || size < 2)
		return;
	
}
