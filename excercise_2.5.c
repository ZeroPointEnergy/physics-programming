
#include <stdio.h>
#include <math.h>

int main(void) 
{
  double x; double a; double b; double d;

  printf("\nPlease enter the angle : ");
  scanf("%lf", &x);
  a = cos(x);
  b =  1- (pow(x,2)/2) + (pow(x,4)/24);

  d = a - b;
  if ( d < 0 ) { d = d * -1; }

  printf("\nThe sine of the angle is %lf", a);
  printf("\nThe sine aproximation is %lf", b);
  printf("\nThe error is %lf\n\n", d);

  return 0;
}
