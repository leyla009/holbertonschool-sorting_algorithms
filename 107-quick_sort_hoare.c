#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Implements the Hoare partition scheme.
 * @array: The array to partition.
 * @size: The full size of the array for printing.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_sort - Recursively sorts the array using Hoare scheme.
 * @array: The array to sort.
 * @size: The full size of the array.
 * @low: The starting index.
 * @high: The ending index.
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int p;

	if (high - low > 0)
	{
		p = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, p - 1);
		hoare_sort(array, size, p, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition).
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
