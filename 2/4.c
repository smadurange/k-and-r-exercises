#include <stdio.h>

#define MAXLEN 1000

void squeeze(char s1[], char s2[]);

/* deletes any character in one string from another string */
int main(int argc, char *argv[]) {
  int i, c;
  char s1[MAXLEN], s2[MAXLEN];

  printf("input first string\n");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s1[i] = c;
  s1[i] = 0;

  printf("input second string\n");
  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    s2[i] = c;
  s2[i] = 0;

  squeeze(s1, s2);
  printf("result: %s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, k, delete;

  for (i = j = 0; s1[i] != 0; i++) {
    delete = 0;
    for (k = 0; s2[k] != 0; k++) {
      if (s1[i] == s2[k]) {
        delete = 1;
        break;
      }
    }

    if (!delete)
      s1[j++] = s1[i];
  }

  s1[j] = 0;
}