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
 * bubble_sort - bubble_sort algorithm
 * @array: int array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size, i;
	int *ptr;

	if (!array || size < 2)
		return;
	while (n > 1)
	{
		ptr = array;
		for (i = 0; i + 1 < n; i++, ptr++)
		{
			if (*ptr > *(ptr + 1))
			{
				swap(ptr, ptr + 1);
				print_array(array, size);
			}
		}
		n--;
	}
}
