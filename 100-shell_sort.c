#include "sort.h"

void swap(int *i, int *j);

/**
 * shell_sort - sort an array using Shell algorithm
 * @arr: array to sort
 * @size: size of the array
 */
void shell_sort(int *arr, size_t size)
{
	size_t i, j, gap = 1;

	if (arr == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap; j -= gap)
			{
				if (arr[j] > arr[j - gap])
					break;
				swap(&arr[j], &arr[j - gap]);
			}
		}
		print_array(arr, size);
	}
}


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
