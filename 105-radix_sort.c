#include "sort.h"
/**
 * max - max value of an array.
 * @a: int array
 * @size: array size
 * Return: integer
 */
int max(int *a, size_t size)
{
	int max = a[0];
	size_t i = 0;

	for (i = 1; i < size; i++)
		if (max < a[i])
			max = a[i];
	return (max);
}
void count(int a[], size_t size, size_t i)
{
    int max=a[0];
 
    for(int i=1;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    int b[max+1];
    for(int i=0;i<max+1;i++)
    {
        b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        b[(a[i]/p)%10]+=1;
    }
    for(int i=1;i<max+1;i++)
    {
       b[i]+=b[i-1];
    }
    int c[n];
    for(int i=0;i<n;i++)
    {
        c[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        c[b[(a[i]/p)%10]-1]=a[i];
        b[(a[i]/p)%10]-=1;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=c[i];
    }
}
/**
 * radix - radix algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: nothing.
 */
void radix_sort(int a[],size_t size)
{
    int max;
 
  	if (!a || size < 2)
  		return;
    max = max(array, size);
    for(int i = 1; max / i > 0; i *= 10)
        count(a, size, i);
}
