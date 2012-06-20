/* This program calculate the product of matrices A[L,M]*B[M,N] = C[L,N]   */
#include <stdio.h>

int main()
{
   int L,M,N;
   int i,j,k;
   int A[10][10], B[10][10], C[10][10];
   printf("Enter the value of M, N and K  (max dim = 10) \n");
   scanf("%d,%d,%d",&L, &M, &N);
   printf("Enter matrix A\n");
   for(i=0;i<L;i++)
      for(j=0;j<M;j++)
      {	     
         printf("A[%d][%d] = ",i,j);
		 scanf("%d",&A[i][j]);
	  }	 
   printf("Enter matrix B\n");	 
   for(j=0;j<M;j++)
      for(k=0;k<N;k++)
	  {
         printf("B[%d][%d] = ",j,k);
  	     scanf("%d",&B[j][k]);
   	  }
   for(i=0;i<L;i++)
      for(k=0;k<N;k++)
      {     	  
         C[i][k]=0;
		 for(j=0;j<M;j++)
		    C[i][k] = C[i][k] + A[i][j]*B[j][k];
	  }  
   printf("\nThe product of matrix A: \n");
   for(i=0;i<L;i++)
   {
      for(j=0;j<M;j++)
         printf("%4d ",A[i][j]);   
      printf("\n");
   }
   printf("\nand matrix B: \n");
   for(j=0;j<M;j++)
   {
      for(k=0;k<N;k++)
         printf("%4d ",B[j][k]);   
      printf("\n");
   }
   printf("\nis matrix C: \n");
   for(i=0;i<L;i++)
   {
      for(k=0;k<N;k++)
         printf("%4d ",C[i][k]);   
      printf("\n");
   }
   return 0;
}
