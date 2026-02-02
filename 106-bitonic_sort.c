#include "sort.h"

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @array: The array to sort.
 * @size: The total size of the original array.
 * @start: The starting index of the sequence to merge.
 * @seq_len: The length of the sequence to merge.
 * @dir: The direction to sort (1 for UP, 0 for DOWN).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq_len,
		   int dir)
{
	size_t i, jump = seq_len / 2;
	int temp;

	if (seq_len > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((dir == 1 && array[i] > array[i + jump]) ||
			    (dir == 0 && array[i] < array[i + jump]))
			{
				temp = array[i];
				array[i] = array[i + jump];
				array[i + jump] = temp;
			}
		}
		bitonic_merge(array, size, start, jump, dir);
		bitonic_merge(array, size, start + jump, jump, dir);
	}
}

/**
 * bitonic_seq - Builds a bitonic sequence recursively.
 * @array: The array to sort.
 * @size: The total size of the original array.
 * @start: The starting index of the sequence.
 * @seq_len: The length of the sequence.
 * @dir: The direction to sort.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq_len, int dir)
{
	size_t cut = seq_len / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (seq_len > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq_len, size, str);
		print_array(array + start, seq_len);

		bitonic_seq(array, size, start, cut, 1);
		bitonic_seq(array, size, start + cut, cut, 0);
		bitonic_merge(array, size, start, seq_len, dir);

		printf("Result [%lu/%lu] (%s):\n", seq_len, size, str);
		print_array(array + start, seq_len);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using Bitonic sort.
 * @array: The array to sort.
 * @size: The size of the array (must be 2^k).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
