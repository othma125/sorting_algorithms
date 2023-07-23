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
 * TopDownMerge - check code.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * @i: low bound index.
 * @k: middle bound index.
 * @j: up bound index.
 */
void TopDownMerge(int *b, int *a, size_t i, size_t k, size_t j)
{
	size_t x = i, y = k, l = i;

	printf("Merging...\n");
	while (l < j)
	{
		if (x < k && (y >= j || a[x] <= a[y]))
		{
			b[l] = a[x];
			x++;
		}
		else
		{
			b[l] = a[y];
			y++;
		}
		l++;
	}
	printf("[left]: ");
	print(a, i, k);
	printf("\n[right]: ");
	print(a, k, j);
	printf("\n[Done]: ");
	print(b, i, j);
	printf("\n");
}
/**
 * TopDownSplitMerge - check code.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * @i: low bound index.
 * @j: up bound index.
 */
void TopDownSplitMerge(int *b, int *a, size_t i, size_t j)
{
	size_t k;

	if (j - i <= 1)
		return;
	k = (j + i) / 2;
	TopDownSplitMerge(a, b, i, k);
	TopDownSplitMerge(a, b, k, j);
	TopDownMerge(b, a, i, k, j);
}
/**
 * merge_sort - merge_sort algorithm
 * @a: int array
 * @size: array size
 */
void merge_sort(int *a, size_t size)
{
	int *b;
	size_t i = 0;

	if (!a || size < 2)
		return;
	b = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		b[i] = a[i];
	TopDownSplitMerge(a, b, 0, size);
	free(b);
}
