#include "sort.h"

/**
 * get_max - Gets the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sorts an array based on a significant digit
 * using counting sort logic.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current significant digit (1, 10, 100, etc.).
 * @output: A buffer to store the sorted result.
 */
void radix_counting_sort(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] so it contains actual position in output[] */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	/* Copy the output array to array[], so it contains sorted numbers */
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_counting_sort(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}
