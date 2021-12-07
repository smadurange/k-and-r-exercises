#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* max depth of val stack */
#define BUFSIZE 100

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

int bufp = 0;      /* next free position in buf */
char buf[BUFSIZE]; /* buffer for ungetch */

/* get next operator or numeric operand */
int getop(char[]);
/* push f onto value stack */
void push(double);
/* pop and return top value from stack */
double pop();

/* reverse Polish calculator with modulus and support for negative numbers */
int main(int argc, char *argv[]) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: division by zero\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push((int)pop() % (int)op2);
      else
        printf("error: division by zero\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
    }
  }

  return 0;
}

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack empty\n");
}

double pop() {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int getch() { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = 0;

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '-')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = 0;

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}