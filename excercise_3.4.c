
#include <stdio.h>
#include <math.h>

void first(void)
{
  printf("\nThe first date is more recent.\n");
}

void second(void)
{
  printf("\nThe second date is more recent.\n");
}

int main(void)
{
  int d1, m1, y1;
  int d2, m2, y2;

  printf("\nEnter a date in the form DD.MM.YYYY: ");
  scanf("%d.%d.%d",&d1,&m1,&y1);
  printf("\nEnter a date in the form DD.MM.YYYY: ");
  scanf("%d.%d.%d",&d2,&m2,&y2);

  if(y1 == y2)
  {
    if(m1 == m2)
    {
      if(d1 == d2)
      {
        printf("\nThe dates are the same.\n");
      }
      else if(d1 > d2){ second(); }
      else { first(); }
    }
    else if(m1 > m2){ second(); }
    else { first(); }
  }
  else if(y1 > y2){ second(); }
  else { first(); }
}
