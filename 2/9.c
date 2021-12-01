#include <stdio.h>

/* counts 1-bits in x */
int bitcount(unsigned x);

int main(int argc, char *argv[]) { return 0; }

int bitcount(unsigned x) {
  // Explanation: on a two's complement system, x - 1 is performed by 
  // adding the two's complement of 1 (i.e. 111...1) to x. Adding 1 to
  // the rightmost 1-bit results in 0 which when &-ed with x, results in 0.
  int b;

  for (b = 0; x != 0; x &= (x - 1))
    b++;

  return b;
}