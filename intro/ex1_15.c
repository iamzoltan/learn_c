#include <stdio.h>

int convertctof(int celsius);
/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ..., 300; functafied */ 
main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;    /* lower limit of temperature table */ 
  upper = 300;  /* upper limit */ 
  step = 20;    /* step size */

  celsius = lower;
  printf("Celsius-Fahrenheit Table\n");
  while (celsius <= upper) {
    fahr = convertctof(celsius);
    printf("%3.0f %6.2f\n", celsius, fahr);
    celsius = celsius + step;
  }
}

int convertctof(int cel)
{
  int fahr;

  fahr = cel * (9.0/5.0) + 32.0;
  return fahr;
}
