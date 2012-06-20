
#include <stdio.h>
#include <math.h>

int main(void) 
{
  int n = 3;
  int v, i;
  float vector[3][n]; 

  // read in the values
  for(v=0; v<2; v++) 
  {
    for(i=0; i<n; i++)
    {
        printf("Vector %d Position %d : ", (v + 1), i);
        scanf("%f", &vector[v][i]);
    }
  }

  // scalar product
  float res = 0;
  for(i=0; i<n; i++)
  {
     res += vector[0][i] * vector[1][i];
  }
  printf("\nScalar product : %f", res);

  // vector product
  for(i=0; i<n; i++)
  {
    vector[2][i] = ( vector[0][(i+1)%3] * vector[1][(i+2)%3] ) - ( vector[0][(i+2)%3] * vector[1][(i+1)%3] );
  }

  printf("\nVector product:\n");
  for(i=0; i<n; i++)
  {
    printf(" | %3.1f |\n", vector[2][i]);
  }
}
