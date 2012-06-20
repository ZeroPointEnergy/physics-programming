#include <math.h>
#include <stdio.h>

//optimized version

int main()
{
	int max;

	printf("Highest Number? ");
	scanf("%d", &max);


	int i;
	// we go from 1 to max and check for each if it is a prime number
	// we know 1 is no prime number, and two is the only even prime number
	
	printf("2 is a prime number\n", i);
	
	//we therefore start with 3, and always increment the number to be checked by 2
	for (i=3; i<=max; i+=2)
	{
			printf("checking if %d is a prime number\n");
		
			int tocheck=3; 
			//this variable will be used for all numbers that need to be checked if they divide i without remainder
			
			int furtherdivisorfound = 0; 
			/*we will set this variable to 1 if we find 
			another divisor inside 2 < d < max. This means 
			that the number cannot be a prime number*/
			
			int limit = ceil(sqrt(i));
			//we will stop above sqrt(i), since if there were two numbers a*b = i (a < sqrt(i), b>sqrt(i) and a,b int), we would have already found it.  ceil means that we round to the next higher integer:
			// ceil(float l) round up to the next integer 
			// floot(float l) round down to the next integer 
			
			while (furtherdivisorfound!=1 && tocheck <= limit)
			{				
				/*we are using a while loop construct here, because we 
				don't know in advance how far we will go. as soo as we 
				find a remainless divisor, we exit the loop using the 
				furtherdivisorfound variable. We lso exit if we reach 
				sqrt(tocheck). see above for explenation why*/

				if ( (i%tocheck) == 0 )  furtherdivisorfound=1;
				tocheck+=1;
			}
			
			if (furtherdivisorfound == 0)
			{
				//if a number has only 2 dividors without remainder (itself and 1), it is a prime number
				printf("+ %d is a prime number\n", i);
			}
	
	}

	return 0;
}

/*


if we run this program (1Ghz PPC G4) up until 20'000 and time it
user	0m0.029s

up to 2'000'000:

user	0m8.587s

(the non-optimzed version managed a limit of 20'000 in that time)

*/

