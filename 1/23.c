#include <stdio.h>

#define NONE 0
#define SINGLLC 1
#define MULTILC 2
#define MAXLEN 1000

/* removes comments from a c program */
int main(int argc, char *argv[]) {
  int prev, curr, i, comment;
  char s[MAXLEN];

  i = prev = 0;
  comment = NONE;

  while (i < MAXLEN - 1 && (curr = getchar()) != EOF) {
    if (!comment) {
      if (curr == '/' && prev == '/') {
        comment = SINGLLC;
        i--;
      } else if (curr == '*' && prev == '/') {
        comment = MULTILC;
        i--;
      } else {
        s[i++] = curr;
      }
    } else if ((comment == SINGLLC && curr == '\n') ||
               (comment == MULTILC && curr == '/' && prev == '*')) {
      comment = NONE;
    }

    prev = curr;
  }

  s[i] = 0;

  printf("c code: \n");
  printf("%s\n", s);

  return 0;
}