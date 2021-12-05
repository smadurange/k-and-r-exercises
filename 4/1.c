#include <stdio.h>

#define MAXLEN 1000

/* finds the rightmost occurrence of t in s */
int strindex(char s[], char t);

int main(int argc, char *argv[]) {
  int i, c, t;
  char s[MAXLEN];

  printf("source: ");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s[i] = c;
  s[i] = 0;

  printf("character: ");
  t = getchar();
  printf("index: %d\n", strindex(s, t));

  return 0;
}

int strindex(char s[], char t) {
  int i, index;

  index = -1;

  for (i = 0; s[i] != 0; i++) {
    if (s[i] == t)
      index = i;
  }

  return index;
}