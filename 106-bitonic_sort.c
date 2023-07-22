#include "sort.h"

void compAndSwap(int a[], int i, int j, int direction) 
{ 
  if (direction == (a[i] > a[j])) 
    swap(a[i], a[j]); 
} 
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
void bitonic_sort(int a[], size_t size) 
{ 
sort(a, 0, size, 1); 
} 
