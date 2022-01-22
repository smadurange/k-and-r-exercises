#include <stdio.h>
#include <stdlib.h>

void entab(char *s, char *t, int *tablist, int tablistc);

int main(int argc, char *argv[]) {
  char op;

  if ((argc != 2 && argc != 3) || (op = argv[1][1] != 'e' && op != 'd')) {
    printf("Usage: -e 5,3...\n");
    return 1;
  }

  

  switch (op) {
  case 'e':
    // todo: entab
    break;
  case 'd':
    // todo: detab
    break;
  default:
    printf("Error: invalid operation.\n");
    return 1;
  }
}