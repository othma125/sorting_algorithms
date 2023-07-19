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
 * shell_sort - bubble_sort algorithm
 * @array: int array
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h = 1;

	if (!array || size < 2)
		return;
	while (h < size / 3)
		h = 3 * h + 1;
	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				swap(array + j, array + j - h);
		}
		h /= 3;
		print_array(array, size);
	}
}
