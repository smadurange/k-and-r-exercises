#include <stdio.h>

#define MAXLINE 1000

int mgetline(char s[], int lim);
void copy(char to[], char from[]);

/* prints the longest input line and the input length */
int main(int argc, char *argv[]) {
  int len, max;
  char s[MAXLINE], smax[MAXLINE];

  max = 0;

  while ((len = mgetline(s, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(smax, s);
    }
  }

  if (max) {
    printf("%s", smax);
    if (max == MAXLINE - 1 && smax[max] != '\n')
      printf("\n");
    printf("max len: %d\n", max);
  }

  return 0;
}

int mgetline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i;
  for (i = 0; (to[i] = from[i]) != '\0'; i++)
    ;
}