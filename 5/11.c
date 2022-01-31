#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXTAB 10
#define TABSIZE 8
#define MAXTEXT 500
#define MAXTABLIST 10

#define GETTEXT(s)                                                             \
  ({                                                                           \
    int i, c;                                                                  \
    for (i = 0; i < MAXTEXT && (c = getchar()) != EOF; i++)                    \
      s[i] = c;                                                                \
    s[i] = 0;                                                                  \
    i;                                                                         \
  })

int gettablist(char *s, int *t);
void entab(char *s, char *t, int *tablist, int tablistc);
void detab(char *s, char *t, int *tablist, int tablistc);

int main(int argc, char *argv[]) {
  int colv[MAXTABLIST], colc;
  char op, s[MAXTEXT + 1], t[MAXTEXT + 1];

  if ((argc != 2 && argc != 3) || ((op = argv[1][1]) != 'e' && op != 'd')) {
    printf("Usage: -e 5,3...\n");
    return 1;
  }

  if (argc == 3) {
    if (!(colc = gettablist(argv[2], colv))) {
      printf("Error: invalid tablist\n");
      return 1;
    }
  } else {
    colv[0] = TABSIZE;
    colc = 1;
  }

  printf("Enter text to %s and press CTRL+D\n", op == 'e' ? "entab" : "detab");
  if (!GETTEXT(s)) {
    printf("Did not receive text!\n");
    return 0;
  }

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

  printf("%s text:\n%s\n", op == 'e' ? "Entabbed" : "Detabbed", t);
  return 0;
}

int gettablist(char *s, int *t) {
  int i, j, k;
  char col[MAXTAB];

  for (i = 0, j = 0, k = 0; j < MAXTABLIST; i++) {
    if (k >= MAXTAB) {
      printf("Error: tablist entry too large\n");
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
      printf("Error: invalid char %c in tablist\n", s[i]);
      return 0;
    }
  }

  return j;
}

void entab(char *s, char *t, int *tablist, int tablistc) {
  int i, j, k, l, m, n;

  if (tablistc < 2) {
    for (i = 0, j = 0; s[i] != 0 && j < MAXTEXT; i++) {
      if (s[i] != ' ')
        t[j++] = s[i];
      else {
        for (k = i; k < i + tablist[0] && s[k] == ' '; k++)
          ;
        if (k == i + tablist[0]) {
          t[j++] = '\t';
          i = k - 1;
        } else
          t[j++] = s[i];
      }
    }

    t[j] = 0;
  } else {
    for (i = 0, j = 0, k = 0, l = 1; i < tablistc && s[j] != 0; j++) {
      if (s[j] != ' ') {
        t[k++] = s[j];
        if (s[j] == '\n') {
          l = 1;
          i = 0;
        } else
          l++;
      } else {
        for (m = j, n = l; n <= tablist[i] && s[m] == ' '; m++, n++)
          ;
        if (n == tablist[i]) {
          t[k++] = '\t';
          l = n + 1;
          for (i += 1; i < tablistc && tablist[i] >= l; i++)
            ;
        } else {
          t[k++] = s[j];
          l++;
        }
      }
    }

    t[k] = 0;
  }
}

void detab(char *s, char *t, int *tablist, int tablistc) {
  int i, j, k, col;

  if (tablistc < 2) {
    for (i = 0, j = 0; j < MAXTEXT && (t[j] = s[i]) != 0; i++) {
      if (s[i] == '\t') {
        for (k = 0; k < TABSIZE && j < MAXTEXT; k++, j++)
          t[j] = ' ';
      } else
        j++;
    }
  } else {
    col = 1;
    for (i = 0, j = 0, k = 0; k < MAXTEXT && s[i] != 0 && j <= tablistc; i++) {
      if (s[i] != '\t') {
        t[k++] = s[i];
        if (s[i] == '\n')
          col = 1;
        else
          col++;
      } else {
        for (; col <= tablist[j] && k < MAXTEXT; col++)
          t[k++] = ' ';
        j++;
      }
    }

    t[k] = 0;
  }
}