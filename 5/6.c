#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void reverse(char *s) {
  int i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    s[i] = s[i] ^ s[j];
    s[j] = s[i] ^ s[j];
    s[i] = s[i] ^ s[j];
  }
}

void mitoa(int n, char *s) {
  int sign;
  char *sp;

  sp = s;

  if ((sign = n) < 0)
    n = -n;

  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    *s++ = '-';
  *s = 0;

  reverse(sp);
}