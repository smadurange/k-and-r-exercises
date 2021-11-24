#include <stdio.h>

void printu(int size);
void prints(int size);

/* prints the max ranges of char, short, int and long */
int main(int argc, char *argv[]) {
  printf("char: ");
  prints(sizeof(char));

  printf("unsigned char: ");
  printu(sizeof(unsigned char));

  printf("short: ");
  prints(sizeof(short));

  printf("unsigned short: ");
  printu(sizeof(unsigned short));

  printf("int: ");
  prints(sizeof(int));

  printf("unsigned int: ");
  printu(sizeof(unsigned int));

  printf("long: ");
  prints(sizeof(long));

  printf("unsigned long: ");
  prints(sizeof(unsigned long));

  return 0;
}

void printu(int size) {
  int bits = 8 * size;
  printf("0 to %ld\n", (1L << (bits - 1)) + ((1L << (bits - 1)) - 1));
}

void prints(int size) {
  int bits = 8 * size;
  printf("%ld to %ld\n", -(1L << (bits - 1)), (1L << (bits - 1)) - 1);
}