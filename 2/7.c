#include <stdio.h>

/* inverts n bits of x starting at p */
unsigned invert(unsigned x, int p, int n) {
  unsigned mask, y;

  // mask to unset n bits starting at p:
  mask = (~0 << p) | ~(~0 << (p - n));

  // invert and extract bits:
  y = ~(x & ~mask) & ~mask;

  // mask out x and copy inverted bits into x:
  return (x & mask) | y;
}