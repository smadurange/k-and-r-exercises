#include <stdio.h>

/* Prints a formatted string containing an invalid escape sequence */

int main(int argc, char *argv[]) {
  printf("hello \c world\n");
  return 0;
}
