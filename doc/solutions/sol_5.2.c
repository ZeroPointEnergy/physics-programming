#include <stdio.h>

int main()
{
   float v1[3], v2[3];
   float sc_prod = 0;
   float v_prod[3];
   int n;
   for (n=0; n<3; n++)
   {
      printf("enter value for v1[%d] ",n);
	  scanf("%f",&v1[n]);
	  printf("enter value for v2[%d] ",n);
	  scanf("%f",&v2[n]);
   }
   for (n=0; n<3; n++)
   {
      sc_prod+=v1[n]*v2[n];
	  v_prod[n] = v1[(n+1)%3]*v2[(n+2)%3]-v2[(n+1)%3]*v1[(n+2)%3];
   }
   printf("The scalar product is %f\n",sc_prod);
   printf("The vector product is (%f,%f,%f)\n",v_prod[0],v_prod[1],v_prod[2]);
   return 0;
}
