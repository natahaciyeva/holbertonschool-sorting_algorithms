#include "sort.h"
#include <stdio.h>
/**
 * _swap - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partition the array using Lomuto scheme
 * @array: The array
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: The pivot index after partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			_swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}

	_swap(&array[i], &array[high]);
	if (i != j)
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_recursive - Recursive quick sort
 * @array: The array
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers using Quick Sort
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
