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
 * bitonicMerge - check code.
 * @a: array.
 * @x: low bound
 * @y: up bound
 * @direction: sorting direction
 * @size: array size
 */
void bitonicMerge(int a[], int x, int y, int direction, size_t size)
{
	int k = y / 2;
	int i;

	if (y > 1)
	{
		for (i = x; i < x + k; i++)
		{
			if (direction == (a[i] > a[i + k]))
				swap(a + i, a + i + k);
		}
		bitonicMerge(a, x, k, direction, size);
		bitonicMerge(a, x + k, k, direction, size);
	}
}
/**
 * sort - check code.
 * @a: array.
 * @x: low bound
 * @y: up bound
 * @direction: sorting direction
 * @size: array size
 */
void bitonicSort(int a[], int x, int y, int direction, size_t size)
{
	int k;

	if (y > 1)
	{
		k = y / 2;
		printf("Merging [%d/%ld] (%s):\n", y, size, (direction) ? "UP" : "DOWN");
		print_array(a + x, y);
		bitonicSort(a, x, k, 1, size);
		bitonicSort(a, x + k, k, 0, size);
		bitonicMerge(a, x, y, direction, size);
		printf("Result [%d/%ld] (%s):\n", y, size, (direction) ? "UP" : "DOWN");
		print_array(a + x, y);
	}
}
/**
 * bitonic_sort - bitonic_sort algorithm.
 * @a: array.
 * @size: array size
 */
void bitonic_sort(int a[], size_t size)
{
	bitonicSort(a, 0, size, 1, size);
}
