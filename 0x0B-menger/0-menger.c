#include "menger.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char **memory(int size) {
    int i;
    char **square;

    /* malloc string for height of square */
    square = malloc(sizeof(char *) * size);
    if (!square)
        return (NULL);
    for (i = 0; i < size; i++) {
    /* malloc string for each row of square */
        square[i] = malloc(sizeof(char *) * size);
    /* if malloc fails for any row, free it along with previous rows */
        if (!square[i]) {
            while (i >= 0) {
                free(square[i]);
                i--;
            }
            free(square);
            return (NULL);
        }
    }
    return (square);
}

void free_square(char **square, int size) {
    while (size--)
        free(square[size]);
    free(square);
}

int edge_cases(int n) {
    if (!n) {
        printf("#\n");
        return (1);
    }
    if (n < 0) {
        return (1);
    }
    return (0);
}

/**
 *print_square - prints the menger buffer to stdo
 *@square: matrix of symbols representing menger square
 *@size: height and width of the square
 *
 *Return: Void.
 */
void print_square(char **square, int size) {
    int y, x;

    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            printf("%c", square[y][x]);
        }
        printf("\n");
    }
    square++;
}


/**
 *menger - create a 2d menger square and print it to stdo
 *@n: size of square
 *
 *Return: Void.
 */
void menger(int n) {
    char **square;
    int size = (int)pow(3, n);
    int y, x = 0;

    if (edge_cases(n))
        return;
    if (!(square = memory(size)))
        return;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            printf("#");
        }
    }
    print_square(square, size);
    free_square(square, size);
}