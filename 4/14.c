#include <stdio.h>

#define swap(t, x, y)                                                          \
  {                                                                            \
    t z = x;                                                                   \
    x = y;                                                                     \
    y = z;                                                                     \
  }

/* Swaps two arguments using a macro */
int main(int argc, char *argv[]) {
  int a, b;
  double x, y;
  char *s1, *s2;

  a = 1;
  b = 2;
  swap(int, a, b);
  printf("\ta=%d, b=%d\n", a, b);

  x = 3.0;
  y = 5.5;
  swap(double, x, y);
  printf("\tx=%f, y=%f\n", x, y);

  s1 = "hello";
  s2 = "world";
  swap(char *, s1, s2);
  printf("\ts1=%s, s2=%s\n", s1, s2);

  return 0;
}