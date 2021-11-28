#include <stdio.h>

#define MAXLEN 1000

int htoi(char s[]);

/* converts positive hex string to decimal */
int main(int argc, char *argv[]) {
  int i, c, d;
  char s[MAXLEN];

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  s[i] = 0;

  d = htoi(s);
  if (d < 0)
    printf("invalid input: %s\n", s);
  else
    printf("decimal value: %d\n", d);

  return 0;
}

int htoi(char s[]) {
  int i, n;
  char c;

  n = 0;

  for (i = 0; (c = s[i]) != 0; i++) {
    if ((i == 0 && c == '0') || (i == 1 && (c == 'x' || c == 'X')))
      continue;
    else if (c >= '0' && c <= '9')
      n = (n << 4) + (c - '0');
    else if (c >= 'A' && c <= 'F')
      n = (n << 4) + (c - 'A' + 10);
    else if (c >= 'a' && c <= 'f')
      n = (n << 4) + (c - 'a' + 10);
    else
      return -1;
  }

  return n;
}