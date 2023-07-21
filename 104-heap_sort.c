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
 * sift_down - check code.
 * @a: int array
 * @start: array start
 * @end: array end
 * @size: array size
 */
void sift_down(int *a, size_t start, size_t end, size_t size)
{
	size_t root = start, swap, child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;
		if (a[swap] < a[child])
			swap = child;
		if (child + 1 ≤ end && a[swap] < a[child + 1])
			swap = child + 1;
		if (root == swap)
			return;
		swap(a + root, a + swap);
		print_array(a, size);
	}
}
/**
 * heapify - check code.
 * @a: int array
 * @size: array size
 */
void heapify(int *a, size_t size)
{
	size_t start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(a, start, size - 1, size);
		start--;
	}
}
/**
 * heap_sort - heap_sort algorithm
 * @a: int array
 * @size: array size
 */
void heap_sort(int *a, size_t size)
{
	size_t n = size - 1, i;

	if (!array || size < 2)
		return;
	heapify(a, n);
	while (n > 0)
	{
		swap(a, a + n);
		print_array(a, size);
		n--;
		sift_down(a, 0, n, size);
	}
}
