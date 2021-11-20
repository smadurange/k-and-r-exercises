#include <stdio.h>

#define MAXLEN 1000

int mygetline(char s[], int max);
void reverse(char s[], int size);

/* reverses input string */
int main(int argc, char *argv[]) {
  int size;
  char s[MAXLEN];

  while ((size = mygetline(s, MAXLEN)) > 0) {
    reverse(s, size);
    printf("%s\n", s);
  }

  if (size == -1) {
    printf("exceeded max input size: %d\n", MAXLEN - 1);
    return 1;
  }

  return 0;
}

int mygetline(char s[], int max) {
  int c, i;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  s[i] = '\0';

  if (i == max - 1 && c != '\n' && c != EOF) {
    c = getchar();
    if (c != '\n' && c != EOF)
      return -1;
  }

  return i;
}

void reverse(char s[], int size) {
  int i, j, upper;

  upper = size / 2;

  for (i = 0; i < upper; i++) {
    j = size - i - 1;
    s[i] = s[i] ^ s[j];
    s[j] = s[i] ^ s[j];
    s[i] = s[i] ^ s[j];
  }
}