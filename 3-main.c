#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
/*	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/

	int array[] = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
/*	int array[] = {0, 1, 2, 3, 5, 4, 6};*/
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
