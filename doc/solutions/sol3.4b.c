#include <stdio.h>

int main()
{
  int d1,d2,m1,m2,y1,y2;
  int comp1,comp2;
  printf("insert first date in the format DD.MM.AAAA \n");
  scanf("%d.%d.%d",&d1,&m1,&y1);
  printf("insert second date in the format DD.MM.AAAA \n");
  scanf("%d.%d.%d",&d2,&m2,&y2);
  printf("\n");
  comp1 = y1*10000 + m1*100 + d1;
  comp2 = y2*10000 + m2*100 + d2;
  if (comp1<comp2)
     printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d1,m1,y1,d2,m2,y2);
  else if (comp1>comp2)
     printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d2,m2,y2,d1,m1,y1);
  else
     printf("it's the same day!!! \n");   
  return 0;
}

