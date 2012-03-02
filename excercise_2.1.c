
#include <stdio.h>

int main(void) 
{
  float a; float b; float x;

  printf("\nPlease enter a : ");
  scanf("%f", &a);

  printf("\nPlease enter b : ");
  scanf("%f", &b);

  if(a == 0)
  {
    printf("\nAsk Chuck Norris (division by zero)\n\n");
    return -1;
  }

  x = - ( b / a );
  printf("\nx is %f\n\n", x);
  return 0;
}
