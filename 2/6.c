#include <stdio.h>

/* sets the n bits of x starting at p to rightmost n bits of y  */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned yLO, yLOA, xUnset, xPrime;

  // extract n LO bits from y
  yLO = y & ~(~0 << n);

  // align extracted bits to p:
  yLOA = yLO << (p + 1 - n);

  // mask to unset n bits starting at p:
  xUnset = (~0 << p) | ~(~0 << (p - n));

  // mask out x:
  xPrime = x & xUnset;

  return xPrime | yLOA;
}