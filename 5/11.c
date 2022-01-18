#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8
#define MAXLEN 1000

void entab(char *s, char *t, int *tablist, int tablistc);

int main(int argc, char *argv[]) {
  int colc, *tablist, *tablistp;
  char *s, *col, *colp, *colstr;

  s = malloc(sizeof(char) * MAXLEN);
  col = malloc(sizeof(char) * MAXLEN);
  colp = col;

  if (argc < 2) {
    tablist = malloc(sizeof(int));
    tablist[0] = 8;
  } else {
    tablist = malloc(sizeof(int) * 100);
    tablistp = tablist;
    for (colstr = argv[1]; *colstr != 0; colstr++) {
      if (*colstr == '"')
        continue;
      if (*colstr == ',' || *colstr == ' ') {
        // todo: realloc based on colc
        colc++;
        *colp++ = 0;
        colp = col;
        *tablistp = atoi(col);
        tablistp++;
      } else {
        *colp++ = *colstr;
      }
    }
  }

  printf("Enter text to entab\n");
  fgets(s, MAXLEN, stdin);

  free(s);
  free(col);
  free(tablist);
}