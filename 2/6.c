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

  // extract LO n bits from y
  yLO = y & ~(~0 << n);

  // align extracted LO bits of y to position p:
  yLOA = yLO << (p + 1 - n);

  // create mask with n bits from position p unset:
  xUnset = (~0 << p) | ~(~0 << (p - n));

  // mask out n bits from x starting at position p:
  xPrime = x & xUnset;

  return xPrime | yLOA;
}