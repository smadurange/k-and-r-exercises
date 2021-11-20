#include <stdio.h>

#define MAXLEN 5

int cgetline(char s[], int max);
void reverse(char s[], int size);

/* reverses input string */
int main(int argc, char *argv[]) {
  int size;
  char s[MAXLEN];

  while ((size = cgetline(s, MAXLEN)) > 0) {
    reverse(s, size);
    printf("%s\n", s);
  }

  if (size == -1) {
    printf("exceeded max input size: %d\n", MAXLEN);
    return 1;
  }

  return 0;
}

int cgetline(char s[], int max) {
  int c, i;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  s[i] = '\0';

  return i == max && c != '\n' && c != EOF ? -1 : i;
}

void reverse(char s[], int size) {
  int i, j, lim;

  lim = size / 2;

  for (i = 0, j = size - i - 1; i < lim; i++) {
    s[i] = s[i] ^ s[j];
    s[j] = s[i] ^ s[j];
    s[i] = s[i] ^ s[j];
  }
}