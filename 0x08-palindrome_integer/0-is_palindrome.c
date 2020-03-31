#include <stdio.h>

unsigned int count_decimal_places(unsigned int num)
{
	unsigned int i;
	unsigned int decimal_places;

	for (i = 1, decimal_places = 0; num / i; i *= 10)
	{
		printf("%d\n", num / i);
		decimal_places += 1;
	}
	return (decimal_places);
}
unsigned int get_divisor(unsigned int decimal_places)
{
	unsigned int divisor;

        for (divisor = 1; decimal_places; decimal_places--)
        {
                divisor *= 10;
        }
        divisor /= 10;
	return (divisor);
}


int main() {
	unsigned int n = 12345678;
	unsigned int i = 1;
	unsigned int decimal_places = 0;
	unsigned int divisor;

	printf("decimal places: %d\n", decimal_places = count_decimal_places(n));
	printf("divisor: %d\n", get_divisor(decimal_places));
	divisor = get_divisor(decimal_places);
	for (i = 10; divisor > 1 && n % i < n; divisor /= 10, i *= 10)
	{
		printf("tilda: %d\n", i);
		printf("divisor: %d\n", divisor);
		printf("n / divisor: %d\n", n / divisor);
		printf("n tilda i: %d\n", n % i);
		printf("(n tilda i) tilda i is: %d\n", (n % i) / (i / 10));
		printf("---------------\n\n");
	}
	return (0);
}
