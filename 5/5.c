#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void mstrncpy(char *s, char *t, int n);
void mstrncat(char *s, char *t, int n);
int mstrncmp(char *s, char *t, int n);

/* Versions of strncpy, strncat and strncmp upto n most char */
int main(int argc, char *argv[]) {
  int n;
  char *s, *t;

  n = 5;
  s = malloc(sizeof(char) * MAXLEN);
  t = "hello, world!";

  mstrncpy(s, t, n);
  printf("mstrncpy: %s\n", s);

  n = 7;
  t = "may the force be with you";

  mstrncat(s, t, n);
  printf("mstrncat: %s\n", s);

  n = 5;
  t = "hello";

  printf("mstrcmp: %d\n", mstrncmp(s, t, n));
  free(s);

  return 0;
}

void mstrncpy(char *s, char *t, int n) {
  for (; n > 0 && (*s++ = *t++) != 0; n--)
    ;
}

void mstrncat(char *s, char *t, int n) {
  for (s += strlen(s); n > 0 && (*s++ = *t++) != 0; n--)
    ;
}

int mstrncmp(char *s, char *t, int n) {
  for (; n > 0 && *t != 0; s++, t++, n--) {
    if (*s != *t)
      return *s - *t;
  }

  return 0;
}
