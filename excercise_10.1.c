
#include <stdio.h>
#include <math.h>


double myfunc(double x)
{
  return 1/sqrt(2.0*M_PI) * exp(-x*x/2.0);
}


/** Integrate the function with the trapezodial method.
 * 
 *  Precision Mode:
 *  Set "max_runs" to 0 if you want to run until the desired precision is reached
 *
 *  Max Run Mode:
 *  Set "max_runs" to the amount of runs you want to calculate.
 *  This Mode ignores the precision parameter.   
 *
 */
void trapezodial_integration(double interval_start, double interval_end, double precision, int max_runs)
{
  double current_precision = 1;
  double interval_length = fabs( interval_end - interval_start );
  double j = 0.5 * ( myfunc(interval_start) + myfunc(interval_end) );
  double area = interval_length * j;
  int run = 1;
  int divisor = 1;
  
  // iterate on the algorythm until precision or max_run is reached
  while( (current_precision > precision) & (run != max_runs) )
  {
    divisor *= 2;

    // Add the middle points to the area
    int numerator = 1;
    double delta_j = 0;
    while( numerator < divisor )
    {
      delta_j += myfunc( interval_start + interval_length * numerator / divisor );
      numerator += 2;
    }

    j += delta_j;
    current_precision = fabs( 2 * delta_j / j - 1 );
    run++;
  }

  area = interval_length * j / divisor ;

  printf("Reached precision of %lf after %d runs. The calculated area is: %lf\n", current_precision, run , area);
  return;
}


/** Integrate the function with the simpson method.
 * 
 *  Precision Mode:
 *  Set "max_runs" to 0 if you want to run until the desired precision is reached
 *
 *  Max Run Mode:
 *  Set "max_runs" to the amount of runs you want to calculate.
 *  This Mode ignores the precision parameter.   
 *
 */
void simpson_integration(double interval_start, double interval_end, double precision, int max_runs)
{
  double current_precision = 1;
  double interval_length = fabs( interval_end - interval_start );
  double interval_middle = ( interval_end + interval_start ) / 2;

  double j = myfunc(interval_start) + myfunc(interval_end);
  double j_borders = j;
  double area = interval_length * j / 3; 
  int run = 1;
  int steps = 1;
  
  // iterate on the algorythm until precision or max_run is reached
  while( (current_precision > precision) & (run != max_runs) )
  {
    
    // Add the middle points to the area 
    double delta_j = 0;
    int i;
    for(i=1; steps > i; i++)
    {
      delta_j += 2 * (1 + i % 2) * myfunc(interval_start + i * interval_length / steps);
    }

    current_precision = fabs(1 - 2 * j / ( j_borders + delta_j ));
    j = j_borders + delta_j;
    run++;
    steps *= 2;
  }

  area = ( interval_length * 2 / steps ) * j / 3 ;

  printf("Reached precision of %lf after %d runs. The calculated area is: %lf\n", current_precision, run , area);
  return;
}


int main(void)
{
  double interval_start = -1; 
  double interval_end = 1;
  double precision = 0.000000001; 
  int max_runs = 5;


  printf("Trapezoidial Rule:\n");
  trapezodial_integration(interval_start, interval_end, precision, max_runs);
  trapezodial_integration(interval_start, interval_end, precision, 0);
  trapezodial_integration(-2, 2, precision, 0);
  trapezodial_integration(-3, 3, precision, 0);
  trapezodial_integration(-4, 4, precision, 0);
  trapezodial_integration(-5, 5, precision, 0);


  printf("Simpson Rule:\n");
  simpson_integration(interval_start, interval_end, precision, max_runs);
  simpson_integration(interval_start, interval_end, precision, 0);
  simpson_integration(-2, 2, precision, 0);
  simpson_integration(-3, 3, precision, 0);
  simpson_integration(-4, 4, precision, 0);
  simpson_integration(-5, 5, precision, 0);
}


