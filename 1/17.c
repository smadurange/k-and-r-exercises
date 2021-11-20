#include <stdio.h>

#define MAXLEN 1001
#define PRNLEN 80

int cgetline(char s[], int max);

/* prints inputs longer than 80 characters */
int main(int argc, char *argv[]) {
  int size;
  char s[MAXLEN];

  while ((size = cgetline(s, MAXLEN)) > 0) {
    if (size >= PRNLEN)
      printf("%s", s);
  }

  if (size == -1) {
    printf("exceeded max input size: %d\n", MAXLEN - 1);
    return 1;
  }

  return 0;
}

int cgetline(char s[], int max) {
  int c, i;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF; i++)
    s[i] = c;
  s[i] = '\0';

  return c != '\n' && c != EOF ? -1 : i;
}