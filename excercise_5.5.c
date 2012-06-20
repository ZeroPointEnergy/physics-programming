
#include <stdio.h>
#include <math.h>

int main(void) 
{
  int limit = 20;

  FILE *f_in  = fopen("data_ger.txt", "r");
  FILE *f_out = fopen("filtered.txt", "w");
  while(feof(f) != 1)
  {
    float x1, x2, x3;
    fscanf(f_in, "%f %f %f", &x1, &x2, &x3);
    if 
  }
  fclose(f);
}
