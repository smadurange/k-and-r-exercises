#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 50

// xplanation of the error:
// In itoa, for largest negative number, n = -n overflows
// resulting in n = INT_MIN (wraps around) causing a god awful mess.

void itoa(int n, char s[]);
void reverse(char s[]);

/* Fixes itoa function to handle the largest negative number */
int main(int argc, char *argv[]) {
  char s[MAXLEN];

  itoa(INT_MIN, s);
  printf("Largest negative number on machine: %d\n", INT_MIN);
  printf("Largest negative number after itoa: %s\n", s);

  return 0;
}

void itoa(int n, char s[]) {
  int i;

  i = 0;

  if (n != INT_MIN) {
    do {
      s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
  }
  else {
    do {
      s[i++] = -(n % 10) + '0';
    } while ((n /= 10) <= -1);
  }

  if (n < 0)
    s[i++] = '-';
  s[i] = 0;
  
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}