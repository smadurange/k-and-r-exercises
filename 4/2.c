#include <ctype.h>
#include <stdio.h>

#define MAXLEN 1000

/* converts string to numeric representation of doubles */
double atof(char s[]);

int main(int argc, char *argv[]) {
  int i, c;
  char s[MAXLEN];

  printf("input: ");

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s[i] = c;
  s[i] = 0;

  printf("numeric: %f\n", atof(s));

  return 0;
}

double atof(char s[]) {
  int i, j, sign, exp, exp_sign;
  double val, power;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E')
    i++;
  exp_sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (exp = 0; isdigit(s[i]); i++)
    exp = 10 * exp + (s[i] - '0');
  if (exp_sign < 0)
    exp = exp_sign * exp;
  if (exp < 0) {
    for (j = exp; j < 0; j++)
      power *= 10.0;
  } else {
    for (j = 0; j < exp; j++)
      power /= 10.0;
  }

  return sign * val / power;
}