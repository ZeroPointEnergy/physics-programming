
#include <stdio.h>
#include <math.h>

int main(void) 
{
  int n = 10;
  int i;
  float input[n]; 

  // read in the values
  for(i=0; i<n; i++)
  {
    scanf("%f", &input[i]);
  }

  // calculate stuff
  float sum = 0;
  for(i=0; i<n; i++)
  {
     sum += input[i];
  }
  float res = sum/n;

  printf("\nResult : %f", res);
}
