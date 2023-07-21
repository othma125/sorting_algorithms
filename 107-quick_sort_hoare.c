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
 * partition - hoare partition.
 * @array: The array of integers.
 * @size: The size of the array.
 * @x: integer.
 * @y: integer.
 * Return: partition index
 */
int partition(int *array, size_t size, int x, int y)
{
	int *pivot, i = x - 1, j = y + 1;

	pivot = array + x;
	while (1)
	{
		do {
			i++;
		} while (array[i] < *pivot);
		do {
			j--;
		} while (array[j] > *pivot);
		if (i >= j)
			return (j);
		swap(array + i, array + j);
		print_array(array, size);
	}
}

/**
 * sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @x: The starting index of the array partition to order.
 * @y: The ending index of the array partition to order.
 * Return: nothing.
 */
void sort(int *array, size_t size, int x, int y)
{
	int p;

	if (x < y)
	{
		p = partition(array, size, x, y);
		sort(array, size, x, p);
		sort(array, size, p + 1, y);
	}
}

/**
 * quick_sort_hoare - quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
