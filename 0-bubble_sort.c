#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort algorithm
 *
 * Description: bubble sort or sinking sort is a simeple sorting
 *    algorithm that repeatedly steps through a list of elements and compares
 *    adjacent elements. If the adjacent elements are in the wrong order,
 *    they are swapped.
 *
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, len = size;
	int tmp, bubbled = 1;

	if (array == NULL || size == 0 || size == 1)
		return;

	while (bubbled == 1)
	{
		bubbled = 0;
		for (index = 0; index < len - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
				bubbled = 1;
			}
		}
		len = len - 1;
	}
}
