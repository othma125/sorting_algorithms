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
 * compAndSwap - check code.
 * @a: array.
 * @x: low bound
 * @y: up bound
 * @direction: sorting direction
 */
void compAndSwap(int a[], int x, int y, int direction)
{
	if (direction == (a[x] > a[y]))
		swap(a + x, a + y);
}
/**
 * bitonicMerge - check code.
 * @a: array.
 * @x: low bound
 * @y: up bound
 * @direction: sorting direction
 */
void bitonicMerge(int a[], int x, int y, int direction)
{
	int k = y / 2;
	int i;

	if (y > 1)
	{
		for (i = x; i < x + k; i++)
			compAndSwap(a, i, i + k, direction);
		bitonicMerge(a, x, k, direction);
		bitonicMerge(a, x + k, k, direction);
	}
}
/**
 * sort - check code.
 * @a: array.
 * @x: low bound
 * @y: up bound
 * @direction: sorting direction
 */
void sort(int a[], int x, int y, int direction)
{
	int k;

	if (y > 1)
	{
		k = y / 2;
		sort(a, x, k, 1);
	        sort(a, x + k, k, 0);
		bitonicMerge(a, x, y, direction);
	}
}
/**
 * bitonic_sort - bitonic_sort algorithm.
 * @a: array.
 * @size: array size
 */
void bitonic_sort(int a[], size_t size)
{
	sort(a, 0, size, 1);
}
