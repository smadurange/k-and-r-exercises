#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8
#define MAXLEN 1000
#define COLCOUNT 100

void entab(char *s, char *t, int *tablist, int tablistc);

int main(int argc, char *argv[]) {
  int colsize;
  int tablistc, *tablist, *tablistp;
  char *s, *col, *colp, *colstr;

  s = malloc(sizeof(char) * MAXLEN);
  col = malloc(sizeof(char) * MAXLEN);
  colp = col;

  if (argc < 2) {
    tablist = malloc(sizeof(int));
    tablist[0] = 8;
  } else {
    tablist = malloc(sizeof(int) * COLCOUNT);
    tablistp = tablist;
    for (colstr = argv[1], tablistc = 0; *colstr != 0; colstr++) {
      if (*colstr == '"')
        continue;
      if (*colstr == ',' || *colstr == ' ') {
        tablistc++;
        if (tablistc != 1 && tablistc % COLCOUNT == 1) {
          tablist = realloc(tablist, sizeof(int) * COLCOUNT);
          if (tablist == NULL) {
            printf("error: realloc\n");
            free(tablist);
            return 1;
          }
        }
        *colp++ = 0;
        colp = col;
        *tablistp = atoi(col);
        tablistp++;
      } else {
        // todo: realloc based on colc
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