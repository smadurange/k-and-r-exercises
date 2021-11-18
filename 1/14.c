#include <stdio.h>

// printable ascii extended charset
#define MAXCHAR 95
#define FCHAR ' '

/* prints a histogram of frequencies of different characters in input */
int main(int argc, char *argv[]) {
  int i, j, c;
  int freq[MAXCHAR];

  for (i = 0; i < MAXCHAR; i++)
    freq[i] = 0;

  while ((c = getchar()) != EOF)
    freq[c - FCHAR]++;

  for (i = 0; i < MAXCHAR; i++) {
    printf("%c: ", i + FCHAR);
    for (j = 0; j < freq[i]; j++)
      putchar('x');
    putchar('\n');
  }

  return 0;
}