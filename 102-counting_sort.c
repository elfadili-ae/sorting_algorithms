#include "sort.h"

/**
 * counting_sort - sort an array using counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int largest = array[0], *countArr, *newArr;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (largest < array[i])
			largest = array[i];

	countArr = malloc(sizeof(int) * largest);
	for (i = 0; i < (size_t)largest; i++)
		countArr[i] = 0;

	for (i = 0; i < size; i++)
		countArr[array[i]] += 1;

	for (i = 0; i < (size_t)largest; i++)
		countArr[i + 1] += countArr[i];

	print_array(countArr, largest + 1);
	newArr = malloc(sizeof(int) * size);
	for (i = 0; i <= size; i++)
		newArr[i] = 0;

	for (i = 0; i < size; i++)
	{
		newArr[countArr[array[i]] - 1] = array[i];
		countArr[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = newArr[i];

	free(countArr);
	free(newArr);
}
