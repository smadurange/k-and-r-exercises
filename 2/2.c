#include <stdio.h>

#define MAXLEN 1000

/* writes input to buffer without using && or || in loop */
int main(int argc, char *argv[]) {
  int i, c;
  char s[MAXLEN];

  for (i = 0; i < MAXLEN - 1; i++) {
    if ((c = getchar()) == EOF) {
      break;
    }

    if (c == '\n') {
      break;
    }

    s[i] = c;
  }

  s[i] = 0;

  return 0;
}