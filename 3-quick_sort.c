#include "sort.h"


/**
 * swap - swap to elements of an array
 * @i: element index
 * @j: element index
 */
void swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * pivot - sort elements by comparing to the pivot
 * @array: array to sort
 * @size: size of the array
 * @lo: low position
 * @hi: high position
 * Return: new pivot
 */
int pivot(int *array, size_t size, int lo, int hi)
{
	int *pivot, i, j;

	pivot = array + hi;
	for (i = j = lo; j < hi; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * quickHelper - quick sort resursive function
 * @array: array to sort
 * @size: size of the array
 * @lo: low position
 * @hi: high position
 */
void quickHelper(int *array, size_t size, int lo, int hi)
{
	int pvt;

	if (hi - lo > 0)
	{
		pvt = pivot(array, size, lo, hi);

		quickHelper(array, size, lo, pvt - 1);
		quickHelper(array, size, pvt + 1, hi);
	}
}

/**
 * quick_sort - sort an array with the quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickHelper(array, size, 0, size - 1);
}
