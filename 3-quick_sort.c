#include "sort.h"

void quickHelper(int *array, size_t size, int lo, int hi);
int pivot(int *array, int size, int lo, int hi);
void swap(int *array, int i, int j);

/**
 * quick_sort - sort an array with the quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quickHelper(array, size, 0, (int) size);
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

	if (lo < hi)
	{
		pvt = pivot(array, size, lo, hi);

		quickHelper(array, size, lo, pvt - 1);
		quickHelper(array, size, pvt + 1, hi);
	}
}

/**
 * pivot - sort elements by comparing to the pivot
 * @array: array to sort
 * @size: size of the array
 * @lo: low position
 * @hi: high position
 * Return: new pivot
 */
int pivot(int *array, int size, int lo, int hi)
{
	int i, j = lo - 1, flag = 0;

	for (i = lo; i < hi; i++)
	{
		if (array[i] <= array[hi])
		{
			j++;
			if (i == j)
				continue;
			flag = 1;
			swap(array, i, j);
			print_array(array, size);
		}
	}
	swap(array, j + 1, hi);
	if (flag)
		print_array(array, size);
	return (j + 1);
}

/**
 * swap - swap to elements of an array
 * @array: array
 * @i: element index
 * @j: element index
 */
void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
}
