#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char *argv[]) {
  int p, n;
  unsigned x, y;

  p = 5;
  n = 3;
  x = 0;
  y = 7;

  printf("New bit field: %x\n", setbits(x, p, n, y));

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned yLO, yLOA, xUnset, xPrime;

  // extract n LO bits from y
  yLO = y & ~(~0 << n);

  // align extracted bits to p:
  yLOA = yLO << (p + 1 - n);

  // mask with n bits from p unset:
  xUnset = (~0 << p) | ~(~0 << (p - n));

  // mask out n bits in x from p:
  xPrime = x & xUnset;

  return xPrime | yLOA;
}