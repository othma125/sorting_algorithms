#include "sort.h"
/**
 * max - max value of an array.
 * @a: int array
 * @size: array size
 * Return: integer
 */
int max(int *a, size_t size)
{
	int mx = 0;
	size_t i = 1;

	for (i = 0; i < size; i++)
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
	int *output, *count;
	size_t i;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);
	if (!output || !count)
		return;
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(a[i] / p) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1;; i--)
	{
		output[count[(a[i] / p) % 10] - 1] = a[i];
		count[(a[i] / p) % 10]--;
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		a[i] = output[i];
	free(count), free(output);
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
	int pow;

	if (!a || size < 2)
		return;
	mx = max(a, size);
	for (pow = 1; mx / pow > 0; pow *= 10)
	{
		count(a, size, pow);
		print_array(a, size);
	}
}
