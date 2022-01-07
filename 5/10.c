#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int main(int argc, char *argv[]) {
  char op[MAXLEN], *s; 
  int val[MAXLEN], i, j, k, op1, op2;

  if (argc == 1) {
    printf("Usage: expr 2 3 4 + *\n");
    return 1;
  }
  
  for(i = 0, j = 0, ++argv; --argc > 0 && i < MAXLEN - 1 && j < MAXLEN - 1; argv++) {
    s = *argv;
    if (isdigit(*s))
      val[i++] = atoi(s);
    else if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '%')
      op[j++] = s[0];
    else {
      printf("error: %s not supported\n", s);
      return -1;
    }
  }

  k = j;
  j = 0;
  
  while (j < k && i > 1) {
    op2 = val[--i];
    op1 = val[--i];
    switch (op[j++]) {
    case '+':
      val[++i] = op1 + op2;
      break;
    case '-':
      val[++i] = op1 - op2; 
      break;
    case '*':
      val[++i] = op1 * op2; 
      break;
    case '/':
      val[++i] = op1 / op2; 
      break;
    case '%':
      val[++i] = op1 % op2; 
      break;
    default:
      printf("error: unkknown op\n");
      return 1;
    }
  }

  printf("\t%d\n", val[i]);

  return 0;
}
