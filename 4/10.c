#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define MAXLINE 1000
#define HEIGHT 1000

#define NUM '0'
#define FUN '1'
#define VAR '2'

int getop(char[]);
void push(double);
double peek();
double pop();
void clear();
double vartoval(char);

int main(int argc, char *argv[]) {
  int type, op1, op2;
  char s[MAXOP];

  printf("Press CTRL+C to exit\n");

  while (type == getop(s)) {
    switch (type) {
    case NUM:
      push(atof(s));
      break;
    case '+':
      op1 = pop();
      op2 = pop();
      if (isalpha(op1))
        op1 = vartoval(op1);
      if (isalpha(op2))
        op2 = vartoval(op2);
      push(op1 + op2);
      break;
    case '-':
      op1 = pop();
      op2 = pop();
      if (isalpha(op1))
        op1 = vartoval(op1);
      if (isalpha(op2))
        op2 = vartoval(op2);
      push(op1 - op2);
      break;
    case '*':
      op1 = pop();
      op2 = pop();
      if (isalpha(op1))
        op1 = vartoval(op1);
      if (isalpha(op2))
        op2 = vartoval(op2);
      push(op1 * op2);
      break;
    case '/':
      op1 = pop();
      op2 = pop();
      if (isalpha(op1))
        op1 = vartoval(op1);
      if (isalpha(op2))
        op2 = vartoval(op2);
      if (op1 == 0.0)
        printf("error: division by zero\n");
      else
        push((double)op2 / op1);
      break;
    case '%':
      op1 = pop();
      op2 = pop();
      if (isalpha(op1))
        op1 = vartoval(op1);
      if (isalpha(op2))
        op2 = vartoval(op2);
      if (op1 == 0.0)
        printf("error: division by zero\n");
      else
        push((int)op2 % (int)op1);
      break;
    case '=':
      break;
    case FUN:
      break;
    default:
      printf("error: unknown command %s\n", s);
    }
  }

  return 0;
}

int ptr = 0;
int line[MAXLINE];

void mgetline() {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
    line[i] = c;
  }
  line[i] = 0;
  ptr = 0;
}

int getop(char s[]) {
  int i, c;

  if (line[ptr] == 0)
    mgetline();

  // get next token
  for (i = 0; i < MAXOP - 1 && (c = line[ptr]) != ' ' && c != 0; i++, ptr++)
    s[i] = c;
  s[i] = 0;

  // opertor, single digit or variable
  if (i == 1) {
    if (isdigit(s[0]))
      return NUM;
    else if (isalpha(s[0]))
      return VAR;
    else
      return s[0];
  }

  if (i > 1 && (isdigit(s[0]) || s[0] == '-' && isdigit(s[1])))
    return NUM;

  // last printed variable
  if (strcmp("LOUT", s) == 0)
    return VAR;

  return FUN;
}

int sp = 0;
double stack[HEIGHT];

void push(double f) {
  if (sp < HEIGHT)
    stack[sp++] = f;
  else
    printf("error: stack empty\n");
}

double pop() {
  if (sp > 0)
    return stack[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double peek() {
  if (sp > 0)
    return stack[sp - 1];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear() {
  for (; sp > 0; sp--)
    ;
}