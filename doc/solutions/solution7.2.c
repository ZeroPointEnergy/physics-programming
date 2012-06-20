// exercise 2

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main(){
  // array-pointers:
  double* a; double* b = 0;
  // number of allocated slots, initialized to a reasonable value
  unsigned int alloc = 2;
  // request memory for a
  a = (double*) malloc(alloc*sizeof(double));
  
  // flag for while loop
  int insertAnotherOne = 1;
  
  // i = current number of inserted numbers, k = helper int
  int i = 0;
  int k;

  printf("insert as many numbers as you want\n");

  while(insertAnotherOne){
    if(i == alloc){    // need to allocate new memory
      // allocate more memory
      b = (double*) malloc(alloc*2*sizeof(double)); // allocate twice the memory of a
      // copy values of a to b
      for(k = 0; k < alloc; k++){
        b[k] = a[k];
      }
      // free a:
      free(a);
      // point a to b
      a = b;
      // keep trac of total allocated memory slots
      alloc *= 2;
    }    
    printf("enter number: ");
    scanf("%lf", &a[i]);
    //a[i] = i+1; // for debug purposes
    // increment number of used slots:
    i++;
    printf("do you want to insert another number?\ntype 1 for yes, 0 for no ");
    scanf("%d", &insertAnotherOne);
    // prevent infinite loop (when debugging):
    if(i == 10000){insertAnotherOne = 0;}
  
  }

  printf("you inserted: \n"); 
  double average = 0;
  for(k = 0; k < i; k++){
    printf("%lf ", a[k]);
    average += a[k];
  }
  average /= i;
  printf("\naverage is: %lf\n", average);  
  return 0;
}


