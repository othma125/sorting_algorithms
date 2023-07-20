#include "sort.h"

/**
 * TopDownMerge - check code.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * @i: low bound index.
 * @k: middle bound index.
 * @j: up bound index.
 */
void TopDownMerge(int *a, int *b, size_t i, size_t k, size_t j)
{
	size_t x = i, y = j, l;

	for (l = i; l < j; l++)
	{
		if (x < k && (x >= j || a[x] <= a[y]))
		{
			b[l] = a[x];
			x++;
		}
		else
		{
			b[l] = a[j];
			y++;
		}
	}
}
/**
 * TopDownSplitMerge - check code.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * @i: low bound index.
 * @j: up bound index.
 */
void TopDownSplitMerge(int *a, int *b, size_t i, size_t j)
{
	size_t k;

	if (j - i <= 1)
		return;
	k = i + (j - i) / 2;
	TopDownSplitMerge(a, b, i, k);
	TopDownSplitMerge(a, b, k, j);
	TopDownMerge(a, b, i, k, j);
}
/**
 * CopyArray - check code.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * @i: low bound index.
 * @j: up bound index.
 */
void CopyArray(int *a, int *b, size_t i, size_t j)
{
	size_t k;

	for (k = i; k < j; k++)
		b[k] = a[k];
}
/**
 * merge_sort - merge_sort algorithm
 * @a: int array
 * @size: array size
 */
void merge_sort(int *a, size_t size)
{
	int *b;

	if (!a || size < 2)
		return;
	b = malloc(size * sizeof(int));
	CopyArray(a, b, 0, size);
	TopDownSplitMerge(a, b, 0, size);
	CopyArray(b, a, 0, size);
	free(b);
}
