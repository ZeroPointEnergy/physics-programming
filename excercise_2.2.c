
#include <stdio.h>
#include <math.h>

int main(void) 
{
  double h; double t;
  const double g = 9.81;

  printf("\nPlease enter the height : ");
  scanf("%lf", &h);
  t = sqrt( (2.0 * h) / g );
  printf("\nThe stone will hit the ground after %lf seconds\n\n", t);
  return 0;
}
