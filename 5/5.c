#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void mstrncpy(char *s, char *t, int n);
void mstrncat(char *s, char *t, int n);
void mstrncmp(char *s, char *t, int n);

int main(int argc, char *argv[]) {
  int n;
  char *s, *t;

  n = 5;
  s = malloc(sizeof(char) * MAXLEN);
  t = "hello, world!";

  mstrncpy(s, t, n);
  printf("mstrncpy: %s\n", s);

  t = "may the force be with you";
  mstrncat(s, t, 7);
  printf("mstrncat: %s\n", s);

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