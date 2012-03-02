#include <stdio.h>


int main()
{
	
	
	//We define the variables
	float balance = 0; 			//initial balance (to be read from user)
	float increase = 0;			//increase (to be read from user)
	float newbalance = 0;		//new balance (we will calculate this)

	printf("Enter starting balance in Swiss Francs\n");
	scanf("%f", &balance); //reading the initial balance from user
													//VERY IMPORTANT: Notice the & in front of the variable
													//read slides from 2.3.2010, slide 10 for explanation

	printf("Enter increased to be credited to account in swiss Francs\n");
	scanf("%f", &increase); //reading the increase

	newbalance = balance + increase; //calculating the nes balance
	
	printf("Account balance (Francs): %.2f\n", newbalance); //printing the result


	return 0;
}