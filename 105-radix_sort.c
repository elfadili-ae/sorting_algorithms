#include "sort.h"

/**
 * ArrayMax - get the max value in the array
 * @arr: array
 * @size: size of the array
 * Return: max value
 */
int ArrayMax(int *arr, size_t size)
{
	int i, max = arr[0];

	for (i = 1; i < (int)size; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * countSort - count sorting based on @digit
 * @arr: array
 * @size: size of the array
 * @digit: digit
 */
void countSort(int *arr, size_t size, int digit)
{
	int *output = NULL;
	int i, count[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		exit(2);

	for (i = 0; i < (int)size; i++)
		count[(arr[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / digit) % 10] - 1] = arr[i];
		count[(arr[i] / digit) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		arr[i] = output[i];

	free(output);
}

/**
 * radix_sort - sort an array using radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int digit, max;

	if (array == NULL || size < 2)
		return;

	max = ArrayMax(array, size);
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		countSort(array, size, digit);
		print_array(array, size);
	}
}
