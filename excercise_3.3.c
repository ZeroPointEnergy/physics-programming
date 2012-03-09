#include <stdio.h>
#include <math.h>

int main()
{
  float a, b, c;
  float discr, realpart, result1, result2;

  printf("\nax^2 + bx + c = 0\n");

  printf("\nEnter a: ");
  scanf("%f", &a);
  printf("\nEnter b: ");
  scanf("%f", &b);
  printf("\nEnter c: ");
  scanf("%f", &c);

  discr = b*b - 4*a*c;
  realpart = -b / (2*a);
  

  if(discr == 0)
  {
    result1 = realpart;
    result2 = realpart;
  }
  else if(discr > 0)
  {
    result1 = realpart + ( sqrt(discr) / (2*a) );
    result2 = realpart - ( sqrt(discr) / (2*a) );
  }
  else
  {
    float imagpart = ( sqrt(-1 * discr)  / (2*a) );
    printf("\nThe results are : %f+i%f, %f-i%f\n", realpart, imagpart, realpart, imagpart);
    return 0;
  }

  printf("\nThe results are : %f, %f\n", result1, result2);
  return 0;
}

