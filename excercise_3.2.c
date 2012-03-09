#include <stdio.h>
#include <math.h>

int main()
{
  float a;

  printf("\nEnter a positive number dude: ");
  scanf("%f", &a);

  if(a <= 0)
  {
    printf("\nDude!\n");
    return -1;
  }

  float wurzela = sqrt(a);
  printf("%f\n",wurzela);
  return 0;
}

