#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * product_helper - print the product as an array
 * @product: array representing the product
 * @len: length of the array
 */
void product_helper(int *product, size_t len)
{
	size_t n;

	if (len == 0 || product == NULL)
	{
		printf("0\n");
		return;
	}
	for (n = *product ? 0 : 1; n < len; ++n)
		printf("%i", product[n]);
	putchar('\n');
}

/**
 * multiply - find product of two string representations of numbers
 * @product: array representing the product
 * @first: first string
 * @second: second string
 * @len_first: length of first string
 * @len_second: length of second string
 */
void multiply(int *product, char *first, char *second, size_t len_first, size_t len_second)
{
	int i, j, carry;

	for (i = len_first - 1; i > -1; --i)
		for (j = len_second - 1; j > -1; --j)
		{
			carry = (first[i] - '0') * (second[j] - '0') + product[i + j + 1];
			product[i + j + 1] = carry % 10;
			product[i + j] += carry / 10;
		}
}

/**
 * check_error - check for problems
 * @argc: number of arguments
 * @argv: main args - argv[0]
 *
 * Return: exits if error, else no return.
 */
void check_error(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (a = 0; argv[a] != NULL; ++a)
		for (b = 0; argv[a][b]; ++b)
			if (argv[a][b] > '9' || argv[a][b] < '0')
			{
				printf("Error\n");
				exit(98);
			}
}

/**
 * main - entry point.
 * @argc: number arguments
 * @argv: array of arguments
 *
 * Return: 0 for success, else 1.
 */
int main(int argc, char *argv[])
{
	size_t len_first, len_second;
	int *product;

	check_error(argc, argv + 1);
	if ( *argv[2] == '0' || *argv[1] == '0')
	{
		product_helper(NULL, 0);
		return (0);
	}
	len_first = strlen(argv[1]);
	len_second = strlen(argv[2]);
	product = calloc(len_first + len_second, sizeof(*product));
	if (product) {
		multiply(product, argv[1], argv[2], len_first, len_second);
		product_helper(product, len_first + len_second);
		free(product);
		return (0);
	}
	return (1);
}
