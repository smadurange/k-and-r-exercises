#include <stdio.h>
#include <stdlib.h>

#define MAXTABLIST 10
#define MAXDIGLEN 10
#define TABSIZE 8
#define MAXINPUT 500

int gettabs(char *s, int *t);
int gettext(char *s, int max);
void entab(char *s, char *t, int *tablist, int tablistc);

int main(int argc, char *argv[]) {
  char op, s[MAXINPUT];
  int colv[MAXTABLIST], colc;

  if ((argc != 2 && argc != 3) || (op = argv[1][1] != 'e' && op != 'd')) {
    printf("Usage: -e 5,3...\n");
    return 1;
  }

  if (argc == 3)
    colc = gettabs(argv[2], colv);
  else {
    colv[0] = TABSIZE;
    colc = 1;
  }

  printf("Enter text to %s\n", op == 'e' ? "entab" : "detab");
  gettext(s, MAXINPUT);

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