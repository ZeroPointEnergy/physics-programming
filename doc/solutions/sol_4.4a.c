#include <math.h>
#include <stdio.h>

int main()
{
	int max;

	printf("Highest Number? ");
	scanf("%d", &max);


	int i;
	// we go from 1 to max and check for each if it is a prime number
	for (i=1; i<=max; i++)
	{
			printf("checking if %d is a prime number\n", i);
		
			int tocheck; //this variable will be used for all numbers that need to be checked if they divide i without remainder
			
			int anzahlganzeteiler=0; // here we will store how many divisors i has
			
			for (tocheck=1; tocheck<=i; tocheck++)	
			{
				// now we check for each number between 1 and i if it divides i without remainder. If we find a number that does, we increase anzahlganzeteiler by 1
				if ( (i%tocheck) == 0 )  anzahlganzeteiler++;
			}
			
			if (anzahlganzeteiler == 2)
			{
				//if a number has only 2 dividors without remainder (itself and 1), it is a prime number
				printf("+ %d is a prime number\n", i);
			}
	
	}

	return 0;
}


/*


if we run this program (1Ghz PPC G4) up until 20'000 and time it

user	0m7.638s

(means processor has worked 7.6s on this problem)


*/