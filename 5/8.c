#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* Sets day of year from month and day */
int day_of_year(int year, int month, int day) {
  int i, leap;

  // leap year logic is only valid if this is true.
  if (year < 1752) {
    printf("error: invalid year\n");
    return -1;
  }

  if (month < 1 || month > 12) {
    printf("error: invalid month\n");
    return -1;
  }

  if (day < 1) {
    printf("error: invalid day\n");
    return -1;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  return day;
}

/* Sets month and day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  if (year < 0) {
    *pmonth = *pday = 0;
    printf("error: invalid year\n");
    return;
  }

  if (yearday < 1) {
    *pmonth = *pday = 0;
    printf("error: invalid yearday\n");
    return;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  *pmonth = i;
  *pday = yearday;
}