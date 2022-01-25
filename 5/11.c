#include <stdio.h>
#include <stdlib.h>

#define MAXTABLIST 10
#define MAXDIGLEN 10
#define TABSIZE 8
#define MAXTEXTLEN 500

int gettabs(char *s, int *t);
int gettext(char *s, int max);
void entab(char *s, char *t, int *tablist, int tablistc);
void detab(char *s, char *t, int *tablist, int tablistc);

int main(int argc, char *argv[]) {
  int colv[MAXTABLIST], colc;
  char op, s[MAXTEXTLEN], t[MAXTEXTLEN];

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

  printf("Enter text to %s and press CTRL+D\n", op == 'e' ? "entab" : "detab");
  gettext(s, MAXTEXTLEN);

  switch (op) {
  case 'e':
    entab(s, t, colv, colc);
    break;
  case 'd':
    detab(s, t, colv, colc);
    break;
  default:
    printf("Error: invalid operation.\n");
    return 1;
  }

  printf("%s:\n%s\n", op == 'e' ? "entabbed" : "detabbed", t);
  return 0;
}

int gettext(char *s, int max) {
  int i, c;

  for (i = 0; i < max && (c = getchar()) != EOF; i++)
    s[i] = c;
  s[i] = 0; 
  return i;
}