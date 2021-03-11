#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * print - print the product
 * @product: array containing the product
 * @len: length of array
 */
void print(int *product, size_t len)
{
	size_t i;

	if (product == NULL || len == 0)
	{
		printf("0\n");
		return;
	}
	for (i = *product ? 0 : 1; i < len; ++i)
		printf("%i", product[i]);
	putchar('\n');
}

/**
 * multiply - get product of string representations of numbers
 * @product: array representing the product
 * @f_len: length of the f string
 * @s_len: length of the s string
 * @f: f number
 * @s: s number
 */
void multiply(int *product, size_t f_len, size_t s_len, char *f, char *s)
{
	int i, k, carry;

	for (i = f_len - 1; i > -1; --i)
		for (k = s_len - 1; k > -1; --k)
		{
			carry = (s[k] - '0') * (f[i] - '0') + product[i + k + 1];
			product[i + k + 1] = carry % 10;
			product[i + k] += carry / 10;
		}
}

/**
 * error_check - check for errors
 * @argc: number of args
 * @argv: arguments
 *
 * Return: exit if error, else Void.
 */
void error_check(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (a = 0; argv[a] != NULL; ++a)
		for (b = 0; argv[a][b]; ++b)
			if (argv[a][b] < '0' || argv[a][b] > '9')
			{
				printf("Error\n");
				exit(98);
			}
}

/**
 * main - entry point
 * @argc: number of args
 * @argv: array of args
 *
 * Return: 0 for success, else 1
 */
int main(int argc, char *argv[])
{
	size_t f_len, s_len;
	int *product;

	error_check(argc, argv + 1);
	if (*argv[1] == '0' || *argv[2] == '0')
	{
		print(NULL, 0);
		return (0);
	}
	f_len = strlen(argv[1]);
	s_len = strlen(argv[2]);
	product = calloc(f_len + s_len, sizeof(*product));
	if (!product)
		return (1);
	multiply(product, f_len, s_len, argv[1], argv[2]);
	print(product, f_len + s_len);
	free(product);
	return (0);
}
