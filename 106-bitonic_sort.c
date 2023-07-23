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
 * compnswap - compare elements and swap
 * @arr: array to sort
 * @i: element index
 * @j: element index
 * @dir: direciton
 */
void compnswap(int *arr, int i, int j, int dir)
{
	if (dir == (arr[i] > arr[j]))
		swap(&arr[i], &arr[j]);
}

/**
 * bitonicMerge - merge subarrays
 * @arr: array to sort
 * @lo: low index
 * @hi: high index
 * @dir: direction
 */
void bitonicMerge(int *arr, size_t lo, size_t hi, int dir)
{
	size_t i, mid;

	if (hi > 1)
	{
		mid = hi / 2;
		for (i = lo; i < lo + mid; i++)
			compnswap(arr, i, i + mid, dir);

		bitonicMerge(arr, lo, mid, dir);
		bitonicMerge(arr, lo + mid, mid, dir);
	}
}

/**
 * bitoniker - bitonic sort resursion
 * @arr: array to sort
 * @size: size of the array
 * @lo: low index
 * @hi: high index
 * @dir: direction
 */
void bitoniker(int *arr, size_t size, size_t lo, size_t hi, int dir)
{
	size_t mid = hi / 2;

	if (hi > 1)
	{

		if (dir == 1)
			printf("Merging [%ld/%ld] (UP):\n", hi, size);
		else
			printf("Merging [%ld/%ld] (DOWN):\n", hi, size);
		print_array(arr + lo, hi);

		bitoniker(arr, size, lo, mid, 1);
		bitoniker(arr, size, lo + mid, mid, 0);


		bitonicMerge(arr, lo, hi, dir);

		if (dir == 1)
			printf("Result [%ld/%ld] (UP):\n", hi, size);
		else
			printf("Result [%ld/%ld] (DOWN):\n", hi, size);
		print_array(arr + lo, hi);
	}
}

/**
 * bitonic_sort - sort an array using the bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitoniker(array, size, 0, size, 1);
}
