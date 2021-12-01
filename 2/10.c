#include <stdio.h>

/* converts ASCII c to lowercase */
int lower(int c) { return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c; }

int main(int argc, char *argv[]) {
  int c;

  for (;;) {
    printf("Enter char to convert to lowercase.\n");
    c = getchar();
    if (c == EOF)
      break;
    else
      printf("%c\n", lower(c));
    
    getchar();
  }

  return 0;
}