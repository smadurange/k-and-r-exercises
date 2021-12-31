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
  s = malloc(sizeof(char) * (n + 1));
  t = "hello, world!";
  
  mstrncpy(s, t, n);
  printf("strncpy: %s\n", s);
  
  free(s);

  return 0;
}

void mstrncpy(char *s, char *t, int n) {
  for (; n > 0 && (*s++ = *t++) != 0; n--)
    ;
}