
#include <stdio.h>
#include <math.h>

int main(void) 
{
  int limit = 20;
  int array[10];
  int i;

  FILE *f = fopen("data.txt", "w");
  for(i=1; i <= limit; i++)
  {
    fprintf(f, "%d\n", (int)pow(2, i)); 
  }
  fclose(f);
}
