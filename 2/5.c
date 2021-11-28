#include <stdio.h>

#define MAXLEN 1000

int any(char s1[], char s2[]);

/* finds the location of first occurrence of any character */
int main(int argc, char *argv[]) {
  int i, c;
  char s1[MAXLEN], s2[MAXLEN];

  printf("Enter first string\n");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s1[i] = c;
  s1[i] = 0;

  printf("Enter second string\n");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s2[i] = c;
  s2[i] = 0;

  printf("Index: %d\n", any(s1, s2));

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != 0; i++) {
    for (j = 0; s2[j] != 0; j++) {
      if (s1[i] == s2[j])
        return i;
    }
  }

  return -1;
}