#include <math.h>
#include <stdio.h>

//compount interest

int main()
{

	float capital; // will be given by user
	float rateofinterest; // will be given by user
	int freq_of_interest; // will be given by user
	int num_years; // will be given by user

	float real_rate_of_interest; // will be calcuclated

	printf("What is the initial captial sum? ");
	scanf("%f", &capital);

	printf("What is the annual rate of interest? (percent) ");
	scanf("%f", &rateofinterest);

	rateofinterest/=100; //we recalculate to fraction

	printf("How many times per year should the interest be collected? ");
	scanf("%d", &freq_of_interest);

	printf("How many years? ");
	scanf("%d", &num_years);
	
	
	real_rate_of_interest = rateofinterest/(float)freq_of_interest;
	/* this is the rate of interest for 1 step. Ex: If we have an 
	annual rate of interest of 6 %, we get a per-moth rate of 
	interest of 0.5 %. We cast freq_of_interest to float because
	we want to make sure it is calculated correctly. Division
	by integer is always dangerous. Check the result with printf
	if you are unsure
	*/
	
	//printf("%f", real_rate_of_interest);
	
	int yearit;
	
	/*in this approech, we create a bested loop, the outer handling 
	the years, the inner handling the steps inside a years. Of course, 
	we could also multiply number of steps per year and number of 
	years and reduce it to one loop.*/
	
	for (yearit=0; yearit<num_years; yearit++)
	{
		int step;
		for (step=0; step<freq_of_interest; step++)
		{
			capital = capital + capital*real_rate_of_interest;
		}
	}
	
	printf("captial after %d years with %d steps per year: %.2f\n", num_years, freq_of_interest, capital);

	return 0;
}