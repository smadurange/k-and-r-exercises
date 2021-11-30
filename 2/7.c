#include <stdio.h>

/* inverts n bits of x starting at p */
unsigned invert(unsigned x, int p, int n);

int main(int argc, char * argv[]) {
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned xUnset, xSet, xInv;

  // mask to unset n bits starting at p:
  xUnset = (~0 << p) | ~(~0 << (p - n));

  // mask to extract bits to invert:
  xSet = ~xUnset;

  // mask out x and copy inverted bits into unset bits:
  xInv = (x & xUnset) | ~(x & xSet);

  return xInv;
}