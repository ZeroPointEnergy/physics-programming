
#include <stdio.h>
#include <math.h>

int main(void) 
{
  double x; double a;

  printf("\nPlease enter the angle : ");
  scanf("%lf", &x);
  a = sin(x);
  printf("\nThe sine of the angle is %lf \n\n", a);
  return 0;
}
