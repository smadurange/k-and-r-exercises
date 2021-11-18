#include <stdio.h>

#define MAXIN 100

/* prints a histogram of lengths of words in the input */
int main(int argc, char *argv[]) {
  int i, j, prev, curr, wordc, charc;
  int stats[MAXIN];

  prev = '0';
  charc = wordc = 0;

  for (i = 0; i < MAXIN; i++)
    stats[i] = 0;

  while ((curr = getchar()) != EOF) {
    if (wordc >= MAXIN) {
      printf("Max word count %d exceeded\n", MAXIN);
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

  for (i = 0;(charc = stats[i]) > 0 && i < MAXIN; i++) {
    printf("%3d: ", i + 1);
    for (j = 0; j < charc; j++)
      putchar('x');
    putchar('\n');
  }

  return 0;
}