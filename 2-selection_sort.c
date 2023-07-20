#include "sort.h"


/**
 * selection_sort - is an effective and efficient sort algorithm
 *                  based on comparison operations.
 *@array: array of integers
 *@size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, low;
	int selected, tmp;

	if (size == 0 || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		selected = 0;
		low = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[low])
			{
				low = j;
				selected = 1;
			}
		}
		if (selected == 1)
		{
			tmp = array[low];
			array[low] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
