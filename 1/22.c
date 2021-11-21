#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

void getstr(char s[]);
void fold(char to[], char from[], int n);

/* folds long input */
int main(int argc, char *argv[]) {
  char s[MAXLEN], f[MAXLEN];

  printf("Enter some text and press ctrl+d to wrap text\n");

  getstr(s);
  fold(f, s, atoi(argv[1]));
  printf("\n%s\n", f);

  return 0;
}

void getstr(char s[]) {
  int i, c;

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; i++)
    s[i] = c;
  s[i] = '\0';
}

void fold(char to[], char from[], int n) {
  int i, j, len, blank;
  char c;

  len = 0;

  for (i = 0, j = 0; j < MAXLEN - 1 && (c = from[i]) != '\0'; i++) {
    blank = c == ' ' || c == '\t';
    if (len == 0 && blank)
      continue;

    if (len >= n && !blank) {
      to[j++] = '\n';
      len = 0;
    }

    to[j++] = c;
    len++;
  }

  to[j] = '\0';
}