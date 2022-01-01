#include <stdio.h>
#include <stdlib.h>

int mgetline(char *s, int lim) {
  int i;

  for (i = 0; i < lim - 1 && (*s++ = getchar()) != EOF && *s != '\n'; i++)
    ;

  if (*s == EOF)
    *s = 0;
  else {
    *++s = 0;
    i++;
  }

  return i;
}

int matoi(char *s) {
  int n;

  for (n = 0; *s >= '0' && *s <= '9'; s++)
    n = 10 * n + (*s - '0');

  return n;
}