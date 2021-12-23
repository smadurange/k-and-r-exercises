#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

void mitoa(int, char[]);
int mgetline(char[], int);

/* Converts an integer to string using recursion */
int main() {
  int n;
  char s1[MAXLEN], s2[MAXLEN];

  while (mgetline(s1, MAXLEN)) {
    n = atoi(s1);
    memset(s2, 0, sizeof(s2));
    mitoa(n, s2);
    printf("\t%s\n", s2);
  }

  return 0;
}

int step = 0;

void mitoa(int n, char s[]) {
  if (n < 0) {
    s[step++] = '-';
    n = -n;
  }

  if (n / 10)
    mitoa(n / 10, s);
  s[step++] = n % 10 + '0';
}

int mgetline(char s[], int max) {
  int c, i;

  step = 0;
  
  for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s[i] = c;
  s[i] = 0;
  
  return c == EOF ? 0 : 1;
}
