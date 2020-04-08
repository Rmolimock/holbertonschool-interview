#include <stdio.h>

int is_palindrome(unsigned long n) {
  unsigned long i, rev = 0;
  i = n;

  while (i != 0) {
    rev = rev * 10;
    rev = rev + i % 10;
    i = i / 10;
  }

  if (n == rev)
    return 1;
  else
    return 0;
}
