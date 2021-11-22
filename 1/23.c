#include <stdio.h>

#define NONE 0
#define SINGLLC 1
#define MULTILC 2

#define MAXLEN 1000

/* removes comments from a c program */
int main(int argc, char *argv[]) {
  int prev, curr, i, comment, inquote;
  char s[MAXLEN];

  inquote = i = prev = 0;
  comment = NONE;

  while (i < MAXLEN - 1 && (curr = getchar()) != EOF) {
    if (!comment) {
      if (curr == '"' && prev != '\\') {
        s[i++] = curr;
        inquote = !inquote;
      } else if (!inquote && curr == '/' && prev == '/') {
        comment = SINGLLC;
        i--;
      } else if (!inquote && curr == '*' && prev == '/') {
        comment = MULTILC;
        i--;
      } else {
        // try not to add redundant line breaks.
        if (i > 0 && s[i - 1] == '\n' && curr == '\n') {
          continue;
        }
        s[i++] = curr;
      }
    } else if (comment == SINGLLC && curr == '\n') {
      comment = NONE;
      // try not to add redundant line breaks.
      if (s[i - 1] != '\n')
        s[i++] = '\n';
    } else if (comment == MULTILC && curr == '/' && prev == '*') {
      comment = NONE;
    }

    prev = curr;
  }

  s[i] = 0;

  printf("Code without comments: \n");
  printf("%s\n", s);

  return 0;
}