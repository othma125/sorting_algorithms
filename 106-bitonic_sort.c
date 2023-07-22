#include "sort.h"
#include <stdio.h>

/**
 * print - check code.
 * @array: The first integer to swap.
 * @i: low bound index.
 * @j: up bound index.
 */
void print(int *array, size_t i, size_t j)
{
	int c = 0;
	size_t l;

	for (l = i; l < j; l++)
	{
		if (c)
			printf(", ");
		c = 1;
		printf("%d", array[l]);
	}
}
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
 */
void bitonicMerge(int a[], int x, int y, int direction)
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
		print(a, x, y);
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
