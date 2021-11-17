#include <stdio.h>

/* replaces one or more blanks with a single blank */
int main(int argc, char *argv[]) {
  int prev, curr;

  prev = 'a';

  while ((curr = getchar()) != EOF) {
    if (prev == ' ' && curr == ' ') {
      continue;
    }

    putchar(curr);
    prev = curr;
  }

  return 0;
}