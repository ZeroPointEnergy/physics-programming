
#include <stdio.h>
#include <math.h>

int main(void) 
{
  int limit = 20;

  FILE *f = fopen("data.txt", "r");
  while(feof(f) != 1)
  {
    int a;
    fscanf(f, "%d", &a);
    printf("%d\n", a);
  }
  fclose(f);
}
