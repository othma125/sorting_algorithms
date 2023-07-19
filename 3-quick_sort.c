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
 * partition - lomuto partition.
 * @array: The array of integers.
 * @size: The size of the array.
 * @x: integer.
 * @y: integer.
 * Return: partition index
 */
size_t partition(int *array, size_t size, size_t x, size_t y)
{
	int pivot;
	size_t i = x, j;

	pivot = array[y];
	for (j = x; j < y; j++)
	{
		if (array[j] < pivot)
		{
			swap(array + j, array + y);
			print_array(array, size);
			i++;
		}
	}

	if (array[y] > pivot)
	{
		swap(array + i, array + y);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @x: The starting index of the array partition to order.
 * @y: The ending index of the array partition to order.
 * Return: nothing.
 */
void sort(int *array, size_t size, size_t x, size_t y)
{
	size_t p;

	if (x < y)
	{
		p = partition(array, size, x, y);
		sort(array, size, x, p - 1);
		sort(array, size, p + 1, y);
	}
}

/**
 * quick_sort - quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
