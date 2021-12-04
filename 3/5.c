#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

/* converts n to string in base b representation */
void itob(int n, char s[], int b);

int main(int argc, char *argv[]) {
  int n, b, c, i;
  char s[MAXLEN];

  printf("Number: ");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s[i] = c;
  s[i] = 0;
  n = atoi(s);

  printf("Base: ");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s[i] = c;
  s[i] = 0;
  b = atoi(s);

  itob(n, s, b);
  printf("%d in base %d: %s\n", n, b, s);

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

void itob(int n, char s[], int b) {
  int i, sign, mod;

  i = 0;
  sign = n < 0;

  if (n >= 0) {
    do {
      mod = (n % b);
      if (mod < 10)
        s[i++] = mod + '0';
      else
        s[i++] = mod - 10 + 'A';
    } while ((n /= b) > 0);
  } else {
    do {
      mod = -(n % b);
      if (mod < 10)
        s[i++] = mod + '0';
      else
        s[i++] = mod - 10 + 'A';
    } while ((n /= b) <= -1);
  }

  if (sign)
    s[i++] = '-';
  s[i] = 0;

  reverse(s);
}
