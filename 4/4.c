#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */
#define FUNCTION '1' /* signal that a custom op was found */
#define MAXVAL 100   /* max depth of val stack */
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

/* returns a value from stack without removing it */
double peek();

/* clears the stack */
void clear();

/* adds commands peek (print top val without popping), dup (duplicate top val),
 * swap (swap top two stack positions), clear (clear stack) */
int main(int argc, char *argv[]) {
  int type;
  double op2, op1;
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
    case FUNCTION:
      if (strcmp("peek", s) == 0)
        peek();
      else if (strcmp("dup", s) == 0)
        push(peek());
      else if (strcmp("swap", s) == 0) {
        op2 = pop();
        op1 = pop();
        push(op2);
        push(op1);
      } else if (strcmp("clear", s) == 0)
        clear();
      else
        printf("error: unknown function %s\n", s);
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

double peek() {
  if (sp > 0)
    return val[sp - 1];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear() {
  for (; sp > 0; sp--)
    ;
}

int getch() { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int getop(char s[]) {
  int i, c, rv;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = 0;

  // operators or line feed
  if (c == '\n' || c == '+' || c == '*' || c == '/' || c == '%')
    return c;

  i = 0;

  // numbers
  if (isdigit(c) || c == '-') {
    // minus operator
    if (c == '-' && !isdigit(s[++i] = c = getch())) {
      ungetch(c);
      s[i] = 0;
      return '-';
    }

    while (isdigit(s[++i] = c = getch()) || c == '.')
      ;
    rv = NUMBER;
  } else {
    // functions
    while (isalnum(s[++i] = c = getch()))
      ;
    rv = FUNCTION;
  }

  s[i] = 0;

  if (c != EOF)
    ungetch(c);

  return rv;
}
