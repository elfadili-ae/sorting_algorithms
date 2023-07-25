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
 * siftDown - sift new first element to its appropriate index
 * @array: array to sort
 * @size: size of the array
 * @root: index of the root node
 * @last: index of the last node
 */
void siftDown(int *array, size_t size, int root, int last)
{
	int left = 2 * root + 1;
	int right =  2 * root + 2;
	int bigger = root;

	if (left < last && array[left] > array[bigger])
		bigger = left;
	if (right < last && array[right] > array[bigger])
		bigger = right;

	if (bigger != root)
	{
		swap(&array[bigger], &array[root]);

		print_array(array, size);
		siftDown(array, size, last, bigger);
	}
}

/**
 * heap_sort - sort an array using heap sort stif down
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = size / 2 - 1; k >= 0; k--)
	{
		siftDown(array, size, k, size - 1);
	}

	for (k = size - 1; k > 0; k--)
	{
		swap(&array[k], &array[0]);

		print_array(array, size);
		siftDown(array, size, 0, k - 1);
	}
}
