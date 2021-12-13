#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXOP 100
#define MAXLINE 1000

#define NUM '0'
#define FUN '1'
#define VAR '2'

int getop(char[]);
void push(double);
double peek();
double pop();
void clear();

int main(int argc, char *argv[]) {
  int type;
  char s[MAXOP];

  printf("Press CTRL+C to exit\n");

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

  return FUN;
}