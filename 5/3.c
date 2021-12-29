#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

void mstrcat(char *, char *);

int main(int argc, char *argv[]) {
  char *s, *t;
  size_t n;

  s = malloc(MAXLEN);
  t = malloc(MAXLEN);
  n = sizeof(s);

  printf("first str: ");
  getline(&s, &n, stdin);

  printf("second str: ");
  getline(&t, &n, stdin);

  mstrcat(s, t);
  printf("strcat: %s\n", s);

  return 0;
}

void mstrcat(char *s, char *t) {
  int i;

  for (i = 0; i < MAXLEN - 1 && *s++; i++)
    ;
  for (s -= 2; i < MAXLEN - 1 && (*s++ = *t++) != '\n'; i++)
    ;
  *s = 0;
}