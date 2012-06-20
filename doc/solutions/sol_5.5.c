#include <stdio.h>
#include <math.h>

int main()
{
   FILE *fr, *fw;
   float px,py,pz;
   fr = fopen("data.txt", "r");
   fw = fopen("filterdata.txt", "w");
   while(!feof(fr))
   {
      fscanf(fr,"%f %f %f",&px,&py,&pz);
	  if (sqrt(pow(px,2)+pow(py,2)) >30.)
	     fprintf(fw,"%.3f %.3f %.3f\n",px,py,pz);
   }
   fclose(fr);
   fclose(fw);
   return 0;
}
