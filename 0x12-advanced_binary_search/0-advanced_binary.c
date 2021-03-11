#include <stdio.h>
#include <stdlib.h>


/**
 * ar_print - print array of integers
 * @array: array to be printed
 * @idx: idx of subarray
 * @stop: end of array
 *
 * Return: Void
 */
void ar_print(int *array, size_t idx, size_t stop)
{
	size_t k = idx;

	printf("Searching in array: ");
	for (k = idx; k < stop; k++)
	{
		printf("%i", array[k]);
		printf(", ");
	}
	printf("%i\n", array[k]);
}

/**
 * helper - recursively search for first value
 * @array: the array being searched
 * @value: the value being searched for in array
 * @idx: current position
 * @stop: where to stop
 * Return: idx of first matching value
 */
int helper(int *array, int idx, int stop, int value)
{
	int mid = ((stop - idx) / 2) + idx;

	ar_print(array, idx, stop);
	if (array[mid] == value)
	{
		if (array[mid - 1] != value)
			return (mid);
	}
	if (idx == stop)
		return (-1);
	if (array[mid] < value)
		return (helper(array, mid + 1, stop, value));
	if (array[mid] >= value)
		return (helper(array, idx, mid, value));
	return (-1);
}

/**
 * advanced_binary - return first matching value in sorted array
 * @array: array being searched
 * @size: size of the array
 * @value: value being searched for
 * Return: index of the first matching value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array)
		return (helper(array, 0, size - 1, value));
	return (-1);
}
