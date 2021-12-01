#include <stdio.h>

/* rotates x to the right by n positions */
unsigned rightrot(unsigned x, int n);

int main(int argc, char *argv[]) {
    unsigned x;

    x = rightrot(0x7, 3);
    printf("rotated: %x\n", x);

    return 0;
}

unsigned rightrot(unsigned x, int n) {
    return (x >> n) | (x << (32 - n));
}