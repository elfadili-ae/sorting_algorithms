#include "sort.h"

void spliter(int *array, size_t size, int lo, int hi, int *barry);
void merger(int *arr, size_t size, int lo, int mid, int hi, int *barr);
void printSubArray(int *array, int lo, int hi);

/**
 * merge_sort - sort an array of integers using merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *barray = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	barray = malloc(sizeof(int) * size);
	if (barray == NULL)
		return;

	for (i = 0; i < size; i++)
		barray[i] = array[i];

	spliter(array, size, 0, size, barray);
	free(barray);
}

/**
 * spliter - split the array to sub-arrays
 * @array: array to sort
 * @size: size of the array
 * @lo: low index
 * @hi: high index
 * @barray: array helper
 *
 */
void spliter(int *array, size_t size, int lo, int hi, int *barray)
{
	size_t mid;

	if (hi - lo <= 1)
		return;

	mid = (hi + lo) / 2;

	spliter(array, size, lo, mid, barray);
	spliter(array, size, mid, hi, barray);

	printf("Merging...\n");

	printf("[left]: ");
	printSubArray(array, lo, mid);
	printf("[right]: ");
	printSubArray(array, mid, hi);

	merger(barray, size, lo, mid, hi, array);
	printf("[Done]: ");
	printSubArray(array, lo, hi);
}

/**
 * merger - merge sub-arrays
 * @arr: array to sort
 * @size: size of the array
 * @lo: low index
 * @mid: mid index
 * @hi: high index
 * @barr: array helper
 */
void merger(int *arr, size_t size, int lo, int mid, int hi, int *barr)
{
	int i = lo, j = mid, k;

	(void)size;
	for (k = lo; k < hi; k++)
	{
		if (i < mid && (j >= hi || arr[i] <= arr[j]))
		{
			barr[k] = arr[i];
			i += 1;
		}
		else
		{
			barr[k] = arr[j];
			j += 1;
		}
	}

	for (k = lo; k < hi; k++)
	{
		arr[k] = barr[k];
	}
}

/**
 * printSubArray - print array
 * @array: array to print
 * @lo: start index
 * @hi: end index
 */
void printSubArray(int *array, int lo, int hi)
{
	int i;

	for (i = lo; i < hi; i++)
	{
		printf("%d", array[i]);
		if (i < hi - 1)
			printf(", ");
	}
	printf("\n");
}
