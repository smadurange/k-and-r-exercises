#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

/* Reverses string in place using recursion */
void reverse(char[], int, int);

int main(int argc, char *argv[]) {
  char *s;
  size_t n;

  s = malloc(sizeof(char) * MAXLEN);

  fgets(s, MAXLEN, stdin);
  reverse(s, 0, strlen(s) - 2);
  printf("\t%s\n", s);

  free(s);
  return 0;
}

void reverse(char s[], int i, int j) {
  if (i < j) {
    reverse(s, i + 1, j - 1);
    s[i] = s[i] ^ s[j];
    s[j] = s[i] ^ s[j];
    s[i] = s[i] ^ s[j];
  }
}