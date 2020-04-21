#include <stdio.h>
#include <math.h>


int block(int col, int row, int n) {
    int right, left;

    right = (int)pow(3, n) - (int)pow(3, n-1);
    left = (int)pow(3, n) / 3;
    if ((col > left && col <= right) && (row > left && row <= right))
        return (0);
    return (1);
}

/**
 *print_menger - recursively print a menger square of n size
 *@n: size of menger square to be printed
 *@top: flags top level recursive call for printing newlines
 *
 *Return: Void.
 */
void print_menger(int n, int top) {
    int row, col;

    top++;
    if (n == 0)
        printf("#");
    for (row = 1; row < (int)pow(3, n) + 1; row++) {
        for (col = 1; col < (int)pow(3, n) + 1; col++) {
            if (block(col, row, n)) {
                printf("#");
                
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/**
 *menger - print a menger square of n size
 *@n: size of menger square to be printed
 *
 *Return: Void.
 */
void menger(int n) {
    if (n < 0)
        return;
    print_menger(n, 1);
}