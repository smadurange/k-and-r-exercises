#include <stdio.h>

#define MAXWRD 100

/* prints a histogram of lengths of words in the input */
int main(int argc, char *argv[]) {
  int i, j, prev, curr, wordc, charc;
  int stats[MAXWRD];

  prev = '0';
  charc = wordc = 0;

  for (i = 0; i < MAXWRD; i++)
    stats[i] = 0;

  while ((curr = getchar()) != EOF) {
    if (wordc >= MAXWRD) {
      printf("Max word count %d exceeded\n", MAXWRD);
      return 1;
    }

    if (curr == ' ' || curr == '\t' || curr == '\n') {
      if (prev != ' ' && prev != '\t' && prev != '\n') {
        stats[wordc++] = charc;
        charc = 0;
      }
    } else {
      charc++;
    }

    prev = curr;
  }

  for (i = 0;(charc = stats[i]) > 0 && i < MAXWRD; i++) {
    printf("%3d: ", i + 1);
    for (j = 0; j < charc; j++)
      putchar('x');
    putchar('\n');
  }

  return 0;
}