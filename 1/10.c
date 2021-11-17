#include <stdio.h>

/* replaces tab with \t, backspace with \b and backslash with \\ */
int main(int argc, char *argv[]) {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      printf("%c", c);
  }

  return 0;
}