#include <stdio.h>

#define MAXLEN 1000
#define TRUE 1
#define FALSE 0

int getlineraw(char s[], int size);
void trim(char to[], char from[], int size);

/* removes trailing blanks and tabs from input */
int main(int argc, char *argv[]) {
  int size;
  char s[MAXLEN], trimmed[MAXLEN];

  while ((size = getlineraw(s, MAXLEN)) > 0) {
    trim(trimmed, s, size);
    printf("%s\n", trimmed);
  }

  if (size == -1) {
    printf("exceeded max input size: %d\n", MAXLEN);
    return 1;
  }

  return 0;
}

int getlineraw(char s[], int size) {
  int c, i;

  for (i = 0; i < size && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  return c != '\n' && c != EOF ? -1 : i;
}

void trim(char to[], char from[], int size) {
  int i, c, trimmed;

  trimmed = FALSE;

  for (i = size - 1; i >= 0; i--) {
    if (!trimmed) {
      c = from[i];
      if (c != ' ' && c != '\t') {
        to[i] = c;
        trimmed = TRUE;
      }
    } else {
      to[i] = from[i];
    }
  }
}