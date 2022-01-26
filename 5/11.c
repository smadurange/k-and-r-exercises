#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXTABLIST 10
#define MAXDIGLEN 10
#define TABSIZE 8
#define MAXTEXTLEN 500

int getinput(char *s, int max);
int gettablist(char *s, int *t);
void entab(char *s, char *t, int *tablist, int tablistc);
void detab(char *s, char *t, int *tablist, int tablistc);

int main(int argc, char *argv[]) {
  int colv[MAXTABLIST], colc;
  char op, s[MAXTEXTLEN], t[MAXTEXTLEN];

  if ((argc != 2 && argc != 3) || ((op = argv[1][1]) != 'e' && op != 'd')) {
    printf("usage: -e 5,3...\n");
    return 1;
  }

  if (argc == 3) {
    if (!(colc = gettablist(argv[2], colv))) {
      printf("error: invalid tablist\n");
      return 1;
    }
  } else {
    colv[0] = TABSIZE;
    colc = 1;
  }

  printf("enter text to %s and press CTRL+D\n", op == 'e' ? "entab" : "detab");
  getinput(s, MAXTEXTLEN);

  switch (op) {
  case 'e':
    // entab(s, t, colv, colc);
    break;
  case 'd':
    // detab(s, t, colv, colc);
    break;
  default:
    printf("error: invalid operation.\n");
    return 1;
  }

  printf("%s:\n%s\n", op == 'e' ? "entabbed" : "detabbed", t);
  return 0;
}

int gettablist(char *s, int *t) {
  int i, j, k;
  char col[MAXDIGLEN];

  for (i = 0, j = 0, k = 0; j < MAXTABLIST; i++) {
    if (k >= MAXDIGLEN) {
      printf("error: tablist entry too large\n");
      return 0;
    }

    if (s[i] == ' ' || s[i] == ',' || s[i] == 0) {
      col[k] = 0;
      t[j++] = atoi(col);
      if (s[i] == 0)
        break;
      else
        k = 0;
    } else if (isdigit(s[i]))
      col[k++] = s[i];
    else {
      printf("error: invalid char %c in tablist\n", s[i]);
      return 0;
    }
  }

  return j;
}

int getinput(char *s, int max) {
  int i, c;

  for (i = 0; i < max && (c = getchar()) != EOF; i++)
    s[i] = c;
  s[i] = 0;
  return i;
}