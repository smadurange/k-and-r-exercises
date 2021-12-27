#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getint(int *);

/* Converts input to an integer using a pointer to a variable */
int main(int argc, char *argv[]) {
  int rc, n;

  while ((rc = getint(&n)) != EOF && rc != 0)
    printf("\t%d\n", n);

  if (rc == 0)
    printf("error: not an integer\n");

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

int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if ((c == '+' || c == '-') && !isdigit(c = getch())) {
    ungetch(c);
    return 0;
  }

  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}