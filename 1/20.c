#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

void getstr(char s[]);
void detab(char to[], char from[], int n);

/* detabs input by replacing tabs with specified number of blanks */
int main(int argc, char *argv[]) {
  int tabw;
  char s[MAXLEN], dtab[MAXLEN];

  tabw = atoi(argv[1]);

  printf("Enter text to detab and press ctrl+d\n");
  
  getstr(s);
  detab(dtab, s, tabw);
  printf("\nTab width: %d\n", tabw);
  printf("%s\n", dtab);

  return 0;
}

void getstr(char s[]) {
  int i, c;

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; i++)
    s[i] = c;
  s[i] = '\0';
}

void detab(char to[], char from[], int n) {
  int i, j, k;
  char c;

  for (i = 0, j = 0; j < MAXLEN - 1 && (c = from[i]) != '\0'; i++) {
    if (c == '\t') {
      for (k = 0; k < n; k++)
        to[j++] = ' ';
    } else {
      to[j++] = from[i];
    }
  }

  to[j] = '\0';
}