
#include <stdio.h>
#include <math.h>


int myrand_func(int a, int x)
{
  return (a * x) % ((int)pow(2,13) - 1);
}


void max_period_of_generator(int a)
{
  int max_counter = 0;
  int max_a;
  int max_seed;
  int counter = 0;

  // We iterate over all the seeds to find the
  // biggest period in the generator
  int seed;
  for (seed = 1; seed < 8191; seed++) {
    counter = 0; 
    
    int x = seed;
    do {
      x = myrand_func(a, x);
      counter++;
    } while (x != seed);

    // if the counter is bigger than max_counter 
    // store the new maximal data
    if (counter > max_counter) {
      max_a = a;
      max_seed = seed;
      max_counter = counter;
    }
  }
  printf("Periodicity: %i (a = %i, seed = %i) \n", counter, a, max_seed); 
}


void simulate_dice(int a)
{
  int results[6] = {0,0,0,0,0,0};

  // Iterate over all seeds
  int seed;
  for (seed = 1; seed < 8191; seed++) {

    int number, roll;
    for(roll = seed; roll <= 3000 + seed; roll++)
    {
      number = myrand_func(a, roll) % 6;
      results[number]++;
    }
  }

  printf("Dice Rolls:\n");
  printf("1: %d\n", results[0]);
  printf("2: %d\n", results[1]);
  printf("3: %d\n", results[2]);
  printf("4: %d\n", results[3]);
  printf("5: %d\n", results[4]);
  printf("6: %d\n", results[5]);
}


int main(void)
{ 
  // FILE *output_file = fopen("excercise_12.1_data.txt", "w");
  
  max_period_of_generator(81);
  max_period_of_generator(83);
  max_period_of_generator(85);

  simulate_dice(81);
  simulate_dice(83);
  simulate_dice(85);

  // fclose(output_file);
  return 0;
}
