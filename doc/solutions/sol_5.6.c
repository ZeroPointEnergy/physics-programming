#include <stdio.h>

int main()
{
   int v[10],i,j,temp;
   for (i=0; i<10; i++)
   {
      printf("Enter no.%d\n",i+1);
	  scanf("%d",&v[i]);
   }
   for(i=0; i<10; i++) 
      for(j=i+1; j<10; j++)
	     if(v[i]>v[j]) //swap the two numbers 
		 { 
		    temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		 }
   for (i=0; i<10; i++)
      printf("no.%d is %d\n",i+1,v[i]);     
   return 0;
}
