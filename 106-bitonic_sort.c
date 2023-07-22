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
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void compAndSwap(int a[], int i, int j, int direction) 
{ 
  if (direction == (a[i] > a[j])) 
    swap(a + i, a + j); 
} 
/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void bitonicMerge(int a[], int x, int y, int direction) 
{
int k = y/2;
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
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void sort(int a[],int x, int y, int direction) 
{
  int k;
	if (y>1) 
	{ 
k = y/2; 
bitonicSort(a, x, k, 1); 
bitonicSort(a, x + k, k, 0); 
bitonicMerge(a, x, y, direction); 
	} 
}
/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void bitonic_sort(int a[], size_t size) 
{ 
sort(a, 0, size, 1); 
} 
