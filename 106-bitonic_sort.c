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

	for (l = i; l <= j; l++)
	{
		if (c)
			printf(", ");
		c = 1;
		printf("%d", array[l]);
	}
	if (c)
		printf("\n");
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
void bitonicMerge(int a[], int x, int y, int direction, size_t size)
{
	int k = y / 2;
	int i;

	if (y > 1)
	{
		printf("Merging [%d/%ld] (%s):\n", k, size, (direction) ? "UP" : "DOWN");
		print(a, x, x + k);
		for (i = x; i < x + k; i++)
		{
			if (direction == (a[i] > a[i + k]))
				swap(a + i, a + i + k);
		}
		printf("Result [%d/%ld] (%s):\n", k, size, (direction) ? "UP" : "DOWN");
		print(a, x, x + k);
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
 */
void bitonicSort(int a[], int x, int y, int direction, size_t size)
{
	int k;

	if (y > 1)
	{
		k = y / 2;
		bitonicSort(a, x, k, 1, size);
		bitonicSort(a, x + k, k, 0, size);
		bitonicMerge(a, x, y, direction, size);
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
