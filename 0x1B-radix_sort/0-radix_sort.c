#include "sort.h"

/**
 * highest - highest value in the array
 * @array: pointer to an int array
 * @size: size of the array
 *
 * Return: highest value in array
 */
int highest(int *array, size_t size)
{
	int highest = 0;
	int sign = (short)size;
	int i;

	for (i = 0; i < sign; i++)
		if (highest < array[i])
			highest = array[i];
	return (highest);
}

/**
 * _sort - helper sort
 * @array: integer array
 * @size: size of the array
 * @num: current num
 *
 * Return: None
 */
void _sort(int *array, size_t size, int num)
{
	int *tmp = NULL;
	int pos[10] = {0};
	int sign = (short)size;
	int i;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	for (i = 0; sign > i; i++)
		pos[(array[i] / num) % 10] += 1;
	for (i = 1; 10 > i; i++)
		pos[i] += pos[i - 1];
	for (i = size - 1; 0 <= i; i--)
	{
		tmp[pos[(array[i] / num) % 10] - 1] = array[i];
		pos[(array[i] / num) % 10]--;
	}
	for (i = 0; sign > i; i++)
		array[i] = tmp[i];
	print_array(tmp, size);
	free(tmp);
}

/**
 * radix_sort - radix sort algorithm
 * @array: an integer array
 * @size: aize of the array
 *
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	int num = 1;
	int high = highest(array, size);
	if (!array)
		return;
	for (num = 1; 0 < high / num; num *= 10)
		_sort(array, size, num);
}
