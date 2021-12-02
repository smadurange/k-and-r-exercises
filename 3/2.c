#include <stdio.h>
#include <string.h>

#define ESCAPE 0
#define UNESCAPE 1
#define MAXLEN 1000

/* converts new line and tab chars to visible chars */
void escape(char s[], char t[]);

/* converts escapes sequences to chars */
void unescape(char s[], char t[]);

int main(int argc, char *argv[]) {
  int c, i, cmd;
  char s[MAXLEN], t[MAXLEN];

  if (!strcmp(argv[1], "e"))
    cmd = ESCAPE;
  else if (!strcmp(argv[1], "u"))
    cmd = UNESCAPE;
  else
    return 1;

  printf("Enter string to %s and press Ctrl+D\n",
         cmd == ESCAPE ? "escape" : "unescape");

  for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF; i++)
    t[i] = c;
  t[i] = 0;

  if (cmd == ESCAPE)
    escape(s, t);
  else
    unescape(s, t);
  
  printf("Output:\n%s\n", s);

  return 0;
}

void escape(char s[], char t[]) {
  int c, i, j;

  for (i = 0, j = 0; (c = t[i]) != 0; i++) {
    switch (c) {
    case '\n': {
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    }
    case '\t': {
      s[j++] = '\\';
      s[j++] = 't';
      break;
    }
    default:
      s[j++] = c;
    }

    s[j] = 0;
  }
}

void unescape(char s[], char t[]) {
  int c, i, j;

  for (i = 0, j = 0; (c = t[i]) != 0; i++) {
    if (j > 0 && s[j - 1] == '\\') {
      switch (c) {
      case 'n':
        s[j - 1] = '\n';
        break;
      case 't':
        s[j - 1] = '\t';
        break;
      default:
        s[j++] = c;
      }
    } else {
      s[j++] = c;
    }
  }

  s[j] = 0;
}