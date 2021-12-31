#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

/* Returns 1 if t occurs at the end of s, 0 otherwise */
int strend(char *s, char *t);

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

  printf("rv: %s\n", strend(s, t) ? "true" : "false");

  return 0;
}

int strend(char *s, char *t) {
  size_t slen, tlen;

  slen = strlen(s);
  tlen = strlen(t);

  if (slen < tlen)
    return 0;

  for (s += slen - tlen; *s != 0; s++, t++) {
    if (*s != *t)
      return 0;
  }

  return 1;
}