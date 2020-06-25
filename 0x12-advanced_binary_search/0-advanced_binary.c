#include <stdlib.h>
#include <stdio.h>


/**
 * print_array - print an array of ints
 * @array: array to be printed
 * @start: idx of start of subarray
 * @end: idx of end of array
 *
 * Return: Void
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in array: ");
	for (i = start; i < end; i++)
	{
		printf("%i", array[i]);
		printf(", ");
	}
	printf("%i\n", array[i]);
}

/**
 * r_check - recursively search sorted array for first value
 * @array: the sorted array being searched through
 * @value: the value being searched for in array
 * @start: idx of the current array pointer in original array
 * @end: idx of the end of the array relative to current
 * Return: the index of the first matching value
 */
int r_check(int *array, int value, int start, int end)
{
	int half = ((end - start) / 2) + start;

	print_array(array, start, end);
	if (array[half] == value)
	{
		if (array[half - 1] != value)
			return (half);
	}
	if (start == end)
		return (-1);
	else if (array[half] >= value)
		return (r_check(array, value, start, half));
	if (array[half] < value)
		return (r_check(array, value, half + 1, end));
	return (-1);
}

/**
 * advanced_binary - find the first matching value in a sorted array
 * @array: the sorted array being searched through
 * @size: the size of array
 * @value: the value being searched for in array
 * Return: the index of the first matching value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (r_check(array, value, 0, size - 1));
}
