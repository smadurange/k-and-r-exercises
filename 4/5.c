
#include <ctype.h>
#include <math.h>
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

/* returns a value from stack without removing it */
double peek();

/* clears the stack */
void clear();

/* adds support sin, exp and power functions */
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
    case 'p':
      peek();
      break;
    case 'c':
      push(peek());
      break;
    case 's':
      op2 = pop();
      op1 = pop();
      push(op2);
      push(op1);
      break;
    case 'd':
      clear();
      break;
    case 'S':
      push(sin(pop()));
      break;
    case 'P':
      push(pow(pop(), pop()));
      break;
    case 'E':
      push(exp(pop()));
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
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = 0;

  if (!isdigit(c) && c != '.' && c != '-' && c != 's' && c != 'p' && c != 'e')
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
  // sin or swap function
  if (c == 's') {
    if ((c = getch()) == ' ')
      return 's';
    else if (c == 'i') {
      if ((c = getch()) == 'n') {
        return 'S';
      } else {
        ungetch(c);
        ungetch('i');
        return 's';
      }
    } else {
      ungetch(c);
      return 's';
    }
  }

  // power function
  if (c == 'p') {
    if ((c = getch()) == 'o') {
      if ((c = getch()) == 'w') {
        return 'P';
      } else {
        ungetch(c);
        ungetch('o');
        return 'p';
      }
    } else {
      ungetch(c);
      return 'p';
    }
  }

  // exponent function
  if (c == 'e') {
    if ((c = getch()) == 'x') {
      if ((c = getch()) == 'p') {
        return 'E';
      } else {
        ungetch(c);
        ungetch('x');
        return 'e';
      }
    } else {
      ungetch(c);
      return 'e';
    }
  }

  s[i] = 0;

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}
