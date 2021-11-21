#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

void getstr(char s[]);
void entab(char to[], char from[], int n);

/* replaces specified number of blanks with a tabstop */
int main(int argc, char *argv[]) {
  int tabw;
  char s[MAXLEN], tabbed[MAXLEN];

  tabw = atoi(argv[1]);

  printf("Enter text to entab and press ctrl+d\n");

  getstr(s);
  entab(tabbed, s, tabw);
  printf("\nTab width: %d\n", tabw);
  printf("%s\n", tabbed);

  return 0;
}

void getstr(char s[]) {
  int i, c;

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; i++)
    s[i] = c;
  s[i] = '\0';
}

void entab(char to[], char from[], int n) {
  int i, j, k, op;
  char c;

  for (i = 0, j = 0; j < MAXLEN - 1 && (c = from[j]) != '\0'; i++) {
    if (c == ' ') {
      op = j + n < MAXLEN - 1;
      for (k = j + 1; op && k < j + n - 1; k++) {
        if (from[k] != ' ') {
          op = 0;
        }
      }

      if (op) {
        to[i] = '\t';
        j += n;
        continue;
      }
    }

    to[i] = c;
    j++;
  }

  to[i] = '\0';
}