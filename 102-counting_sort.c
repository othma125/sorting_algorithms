#include "sort.h"
#include <limits.h>

/**
 * max - max value of an array.
 * @array: int array
 * @size: array size
 */
int max(int *a, size_t size)
{
	int max = INT_MIN;
	size_t i = 0;

	for (i = 0; i < size; i++)
		if (max < a[i])
			max = a[i];
	return (max);
}
/**
 * counting_sort - bubble_sort algorithm
 * @array: int array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int k, *count, *output;

	if (!array || size < 2)
		return;
	k = max(array, size);
	count = malloc((k + 1) * sizeof(int));
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; I < (size_t)k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k + 1);
	output = malloc(size * sizeof(int));
	i = size;
	while (i > 0)
	{
		i--;
		count[array[i]]--;
		output[count[array[i]]] = array[i];
	}
	free(array);
	array = output;
	free(count);
}
