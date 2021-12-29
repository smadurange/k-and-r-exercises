#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

/* Copies str t to the end of str s */
void mstrcat(char *s, char *t);

int main(int argc, char *argv[]) {
  char *s, *t;

  s = malloc(sizeof(char) * MAXLEN);
  t = malloc(sizeof(char) * MAXLEN);

  printf("first str: ");
  fgets(s, MAXLEN, stdin);
  s[strlen(s) - 1] = 0;

  printf("second str: ");
  fgets(t, MAXLEN, stdin);
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