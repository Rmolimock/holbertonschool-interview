#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * _switch - _switchs ints
 * @a: integer to _switch
 * @b: integer to _switch
 */
void _switch(int *a, int *b)
{
	*a *= *b;
	*b = *a / *b;
	*a = *a / *b;
}

/**
 * convert_into_heap - convert array into max heap
 * @array: an array of ints
 * @index: the current index of the arrau
 * @size: the size of the array
 * @len: boundaries
 */
void convert_into_heap(int *array, int size, int index, int len)
{
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int max = index;

	if (array[left] > array[max] && left > 0 && left < len)
		max = left;
	if (array[right] > array[max] && right > 0 && right < len)
		max = right;
	if (max != index)
	{
		_switch(array + max, array + index);
		print_array(array, size);
		convert_into_heap(array, size, max, len);
	}
}
/**
 * heap_sort - sort ints using a heap algo
 * @array: array of ints to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int end = size - 1;

	for (i = (size / 2) - 1; i >= 0; i--)
		convert_into_heap(array, size, i, size);
	for (end = size - 1; end > 0; end--)
	{
		_switch(array + end, array);
		print_array(array, size);
		convert_into_heap(array, size, 0, end);
	}
}
