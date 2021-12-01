#include <stdio.h>

/* rotates x to the right by n positions */
unsigned rightrot(unsigned x, int n) {
    return (x >> n) | (x << (32 - n));
}