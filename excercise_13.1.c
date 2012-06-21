
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double my_func(double x)
{
  return exp(- x * x / 2.0) / sqrt(2.0 * M_PI);
}


double monte_carlo_integration(double interval_start, double interval_end, int steps) 
{
  // seed srand with currend time
  srand(time(NULL));

  double sum = 0;

  // for every step we evaluate the funtion at
  // a random position and add it to the area
  int i; double x;
  for (i = 0; i < steps; i++) {

    // Get a random number from inside the definet interval
    x = ((interval_end - interval_start) * (double) rand() / (double) RAND_MAX) + interval_start;

    sum += my_func(x);
  }

  return (interval_end - interval_start) * sum / (double) steps;
}


int main(void)
{ 
  // FILE *output_file = fopen("excercise_12.1_data.txt", "w");

  double interval_start =  -1;
  double interval_end   =   1;
  int    steps          = 10e6;


  double area = monte_carlo_integration(interval_start, interval_end, steps);

  printf("Area in the given interval: %g\n", area                    );
  printf("Error (Theory)            : %g\n", 8.0 / sqrt(steps - 1)   );
  printf("Error (Simulation)        : %g\n", fabs(0.68268949 - area) );

  // fclose(output_file);
  return 0;
}
