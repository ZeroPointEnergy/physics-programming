#include <stdio.h>
#include <math.h>

int main()
{
   float v,alpha_rad,alpha_gra,t,x0=0,y0=2,vx0,vy0;
   float x,y=0;
   const float pi = 3.141592;
   printf("Enter the value for |v| in m/s: ");
   scanf("%f",&v);
   printf("Enter the value for alpha (in degrees)" );
   scanf("%f", &alpha_gra);
   alpha_rad = alpha_gra*pi/180.; 
   vx0 = v*cos(alpha_rad); 
   vy0 = v*sin(alpha_rad); 
   t=0; x=x0; y=y0;
   while(y>=0)
   {
      printf("t = %.1f x= %.2f y=%.2f \n",t,x,y);
	  t+=0.5;
	  x = x0 + vx0*t;
	  y = y0 + vy0*t - 0.5*9.8*pow(t,2);
   }
   return 0;
}
