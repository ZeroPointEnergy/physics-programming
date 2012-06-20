#include <stdio.h>

int main()
{
  int d1,d2,m1,m2,y1,y2;
  printf("insert first date in the format DD.MM.AAAA \n");
  scanf("%d.%d.%d",&d1,&m1,&y1);
  printf("insert second date in the format DD.MM.AAAA \n");
  scanf("%d.%d.%d",&d2,&m2,&y2);
  printf("\n");
  if (y1>y2)
  {
     printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d2,m2,y2,d1,m1,y1);
  }
  else if(y1<y2) 
  {
     printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d1,m1,y1,d2,m2,y2);
  }
  else
  {
     if(m1>m2)
	 {
	    printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d2,m2,y2,d1,m1,y1);
	 }
	 else if(m1<m2)
	 {
	    printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d1,m1,y1,d2,m2,y2);
	 }
	 else
	 {
	    if(d1>d2)
	    {
	       printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d2,m2,y2,d1,m1,y1);
	    }
	    else if(d1<d2)
	    {
	       printf("%02d.%02d.%04d is before %02d.%02d.%04d\n",d1,m1,y1,d2,m2,y2);
	    }
	    else
	    {
	       printf("it's the same day!!! \n");
	    }
	 }
  }
  return 0;
}

