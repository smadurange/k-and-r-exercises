#include <stdio.h>

/* prints a conversion table from celsius to fahrenheit */
int main(int argc, char *argv[]) {
  float celsius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  celsius = lower;

  printf("celsius\tfahrenheit\n");

  while (celsius <= upper) {
    fahr = (celsius * 9.0 / 5.0) + 32.0;
    printf("%7.0f\t%10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}