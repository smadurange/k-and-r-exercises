#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  s[strlen(s) - 1] = 0;

  printf("second str: ");
  getline(&t, &n, stdin);
  t[strlen(t) - 1] = 0;

  mstrcat(s, t);
  printf("strcat: %s\n", s);

  return 0;
}

void mstrcat(char *s, char *t) {
  int i;

  for (i = 0; i < MAXLEN && *s++; i++)
    ;
  for (s--; i < MAXLEN && (*s++ = *t++); i++)
    ;
}