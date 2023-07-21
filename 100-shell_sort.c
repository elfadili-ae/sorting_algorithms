#include "sort.h"

void swap(int *i, int *j);
int _pow(int x, int y);

/**
 * shell_sort - sort an array using Shell algorithm
 * @arr: array to sort
 * @size: size of the array
 */
void shell_sort(int *arr, size_t size)
{
	size_t i, gap, flag = 0;

	if (arr == NULL || size < 2)
		return;

	for (gap = (_pow(3, size) - 1) / 2; gap > 0; gap /= 2)
	{
		flag = 0;
		for (i = 0; i < size; i++)
		{
			if ((gap + i) >= size)
				break;
			if (arr[i] > arr[gap + i])
			{
				flag = 1;
				swap(&arr[i], &arr[gap + i]);
			}
		}
		if (flag)
			print_array(arr, size);
	}

	flag = 0;
	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[1 + i])
		{
			flag = 1;
			swap(&arr[i], &arr[1 + i]);
		}
	}
	if (flag)
		print_array(arr, size);
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

/**
 * _pow - calculate the power of a number
 * @x: number
 * @y: power
 * Return: @n power of @y
 */
int _pow(int x, int y)
{

	if (y == 0)
		return (1);
	if (y > 0)
		return (x * _pow(x, y - 1));
	return (-1);
}
