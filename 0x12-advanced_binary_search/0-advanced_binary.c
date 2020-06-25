#include <stdlib.h>
#include <stdio.h>


/**
 * print_array - print an array of ints
 * @array: array to be printed
 * @size: size of the array
 *
 * Return: Void
 */
void print_array(int *array, size_t size)
{
	size_t i = 0;

	printf("Searching in array: ");
	while (i < size)
	{
		if (i != 0)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * r_check - recursively search sorted array for first value
 * @array: the sorted array being searched through
 * @size: the size of array
 * @value: the value being searched for in array
 * @idx: idx of the current array pointer in original array
 * Return: the index of the first matching value
 */
int r_check(int *array, size_t size, int value, int idx)
{
	int half = size / 2;
	int *mid = array + half;

	if (!array)
		return (-1);
	else if (!half)
		return (-1);
	print_array(array, size);
	if (array[half] == value)
	{
		if ((half - 1) > idx && array[half - 1] == value)
			return (r_check(array + idx, half, value, idx));
		return (idx + half);
	}
	else if (value < array[half])
		return (r_check(array, half, value, half));
	return (r_check(mid, half, value, half + idx));
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
	int half = size / 2;
	int *mid = array + half;

	if (!array)
		return (-1);
	print_array(array, size);
	if (value == array[half])
		return (half);
	else if (value < array[half])
		return (r_check(array, half, value, 0));
	return (r_check(mid, half, value, half));
}
