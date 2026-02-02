#include "sort.h"

/**
 * swap_items - Swaps two integers in an array.
 * @array: The array.
 * @size: The full size of the array for printing.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_items(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to partition.
 * @size: The full size of the array for printing.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition (pivot).
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_items(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap_items(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * lomuto_sort - Recursively sorts the array using Lomuto.
 * @array: The array to sort.
 * @size: The full size of the array for printing.
 * @low: The starting index.
 * @high: The ending index.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int p = lomuto_partition(array, size, low, high);

		lomuto_sort(array, size, low, p - 1);
		lomuto_sort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
