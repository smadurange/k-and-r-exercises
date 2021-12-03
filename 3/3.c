#include <ctype.h>
#include <stdio.h>

#define MAXLEN 1000

/* expands shorthand notation like a-z and 0-9 for ASCII charset */
void expand(char s1[], char s2[]);

int main(int argc, char *argv[]) {
  int i;
  char c, s1[MAXLEN], s2[MAXLEN];

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s1[i] = c;
  s1[i] = 0;

  expand(s1, s2);
  printf("%s\n", s2);

  return 0;
}

void expand(char s1[], char s2[]) {
  int i, j, c;

  for (i = 0, j = 0; j < MAXLEN - 1 && (c = s1[i]) != 0; i++) {
    if (c == '-' && i > 0 && isalnum(s1[i - 1]) && isalnum(s1[i + 1])) {
      c = s1[i - 1] + 1;
      while (c < s1[i + 1])
        s2[j++] = c++;
      continue;
    }

    s2[j++] = c;
  }

  s2[j] = 0;
}