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