#include <stdio.h>

/* prints input one word per line */
int main(int argc, char *argv[]) {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t')
      printf("\n");
    else
      putchar(c);
  }

  return 0;
}