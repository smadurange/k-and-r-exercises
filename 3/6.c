#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

/* converts n to s with width w */
void itoa(int n, char s[], int w);

int main(int argc, char *argv[]) {
  int i, c, n, w;
  char s[MAXLEN];

  printf("Number to convert to string: ");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s[i] = c;
  s[i] = 0;
  n = atoi(s);

  printf("Width: ");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s[i] = c;
  s[i] = 0;
  w = atoi(s);

  itoa(n, s, w);
  printf("%d as string of width %d: %s\n", n, w, s);

  return 0;
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int w) {
  int i;

  i = 0;

  if (n >= 0) {
    do {
      s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
  } else {
    do {
      s[i++] = -(n % 10) + '0';
    } while ((n /= 10) <= -1);
  }

  if (n < 0)
    s[i++] = '-';

  while (i < MAXLEN - 1 && i < w)
    s[i++] = ' ';

  s[i] = 0;

  reverse(s);
}