#include "sort.h"
/**
 * max - max value of an array.
 * @a: int array
 * @size: array size
 * Return: integer
 */
int max(int *a, size_t size)
{
	int mx = a[0];
	size_t i = 1;

	for (i = 1; i < size; i++)
		if (mx < a[i])
			mx = a[i];
	return (mx);
}
/**
 * count - check code.
 * @a: int array
 * @size: array size
 * @p: array size
 * Return: integer
 */
void count(int a[], size_t size, int p)
{
	int mx, *b, *c;
	int i;

	mx = max(a, size);
	b = malloc(sizeof(int) * (mx + 1));
	for (i = 0; i <= mx; i++)
		b[i] = 0;
	for (i = 0; (size_t)i < size; i++)
		b[(a[i] / p) % 10] += 1;
	for (i = 1; i <= mx; i++)
		b[i] += b[i - 1];
	c = malloc(sizeof(int) * size);
	for (i = 0; (size_t)i < size; i++)
		c[i] = 0;
	for (i = 0; (size_t)i < size; i++)
	{
		c[b[(a[i] / p) % 10] - 1] = a[i];
		b[(a[i] / p) % 10] -= 1;
	}
	for (i = 0; (size_t)i < size; i++)
		a[i] = c[i];
	free(c), free(b);
}
/**
 * radix_sort - radix algorithm.
 * @a: An array of integers.
 * @size: The size of the array.
 * Return: nothing.
 */
void radix_sort(int a[], size_t size)
{
	int mx;
	int i;

	if (!a || size < 2)
		return;
	mx = max(a, size);
	for (i = 1; mx / i > 0; i *= 10)
		count(a, size, i);
}
