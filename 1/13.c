#include <stdio.h>

#define MAXWRD 100

/* prints a histogram of lengths of words in the input */
int main(int argc, char *argv[]) {
  int i, j, p, c, wc, cc, size;
  int data[MAXWRD];

  p = '0';
  cc = wc = 0;

  for (i = 0; i < MAXWRD; i++)
    data[i] = 0;

  while ((c = getchar()) != EOF) {
    if (wc >= MAXWRD) {
      printf("Max word count %d exceeded\n", MAXWRD);
      return 1;
    }

    if (c == ' ' || c == '\t' || c == '\n') {
      if (p != ' ' && p != '\t' && p != '\n') {
        data[wc++] = cc;
        cc = 0;
      }
    } else {
      cc++;
    }

    p = c;
  }

  for (i = 0; i < MAXWRD; i++) {
    size = data[i];
    if (size == 0)
      break;

    printf("%3d: ", i + 1);
    for (j = 0; j < size; j++)
      putchar('x');
    putchar('\n');
  }

  return 0;
}