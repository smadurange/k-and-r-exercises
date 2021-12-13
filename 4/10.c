#include <stdio.h>
#include <string.h>

#define MAXOP 100
#define MAXLINE 1000

#define NUM '0'
#define FUN '1'
#define ASG '2'
#define VAR '3'

int getop(char[]);
void push(double);
double peek();
double pop();
void clear();

int main(int argc, char *argv[]) {
  int type;
  char s[MAXOP];

  while (type == getop(s)) {
    switch (type) {
    case NUM:
      break;
    case '+':
      break;
    case '-':
      break;
    case '*':
      break;
    case '/':
      break;
    case '%':
      break;
    case FUN:
      break;
    case ASG:
      break;
    case VAR:
      break;
    default:
      printf("error: unknown command %s\n", s);
    }
  }

  return 0;
}