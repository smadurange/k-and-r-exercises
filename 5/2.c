#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getfloat(float *);

/* Converts input string to a float using a ptr to a variable */
int main(int argc, char *argv[]) {
  int rc;
  float f;

  while ((rc = getfloat(&f)) != EOF && rc != 0)
    printf("\t%.8g\n", f);

  if (rc == 0)
    printf("error: not a valid number\n");

  return 0;
}

char buf[BUFSIZE];
int bufp = 0;

int getch() { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int getfloat(float *pf) {
  int c, sign, rad, div;

  rad = 0;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if ((c == '+' || c == '-') && !isdigit(c = getch()) && c != '.') {
    ungetch(c);
    return 0;
  }

  for (*pf = 0.0, div = 1.0; isdigit(c) || c == '.'; c = getch()) {
    if (c == '.') {
      if (rad > 0)
        return 0;
      rad++;
      continue;
    }
    if (rad)
      div *= 10;
    *pf = 10.0 * *pf + (c - '0');
  }

  *pf = sign * *pf / div;

  if (c != EOF)
    ungetch(c);

  return c;
}