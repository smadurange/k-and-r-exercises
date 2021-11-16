#include <stdio.h>

/* counts blanks, tabs and newlines in input */
int main(int argc, char *argv[]) {
  int c, bc, tc, nc;

  bc = tc = nc = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      bc++;
    else if (c == '\t')
      tc++;
    else if (c == '\n')
      nc++;
  }

  printf("blanks: %d, tabs: %d, newlines: %d\n", bc, tc, nc);
  return 0;
}