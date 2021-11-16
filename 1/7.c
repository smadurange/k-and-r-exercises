
#include <stdio.h>

/* prints the value of EOF */
int main(int argc, char *argv[]) {
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  printf("Value of EOF: %d\n", c);
  return 0;
}