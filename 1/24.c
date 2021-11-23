#include <stdio.h>

#define MAXLEN 1000
#define TRUE 1
#define FALSE 0

#define INLINE 2
#define MULTILINE 3

/* checks c program for unbalanced parentheses, brackets and braces */
int main(int argc, char *argv[]) {
  int p, c, i, comment, quote, parens, bracks, braces;

  p = 0;
  comment = quote = FALSE;
  parens = bracks = braces = 0;

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; i++) {
    if (!comment && !quote && (c == '/' || c == '*') && p == '/') {
      comment = c == '/' ? INLINE : MULTILINE;
      continue;
    }
    if (!comment && !quote && c == '"') {
      quote = TRUE;
      continue;
    }
    if (comment == INLINE && c == '\n') {
      comment = FALSE;
      continue;
    }
    if (comment == MULTILINE && c == '/' && p == '*') {
      comment = FALSE;
      continue;
    }
    if (!comment && quote && c == '"' && p != '\\') {
      quote = FALSE;
      continue;
    }
    if (!comment && !quote) {
      if (c == '{')
        braces++;
      else if (c == '(')
        parens++;
      else if (c == '[')
        bracks++;
      else if (c == '}')
        braces--;
      else if (c == ')')
        parens--;
      else if (c == ']')
        bracks--;
    }
  }

  if (braces != 0)
    printf("err: input contains %d open braces\n", braces);
  if (parens != 0)
    printf("err: input contains %d open parentheses\n", parens);
  if (bracks != 0)
    printf("err: input contains %d open brackets\n", bracks);

  if (braces == 0 && parens == 0 && bracks == 0)
    printf("all braces, parenthese and brackets are balanced!\n");

  return 0;
}