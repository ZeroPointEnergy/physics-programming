
#include <stdio.h>
#include <math.h>


double myfunc(double x)
{
  return exp(-x) - x;
}


/** Finds one root in the given interval with the bisection method.
 * 
 *  Precision Mode:
 *  Set "max_runs" to 0 if you want to run until the desired precision is reached
 *
 *  Max Run Mode:
 *  Set "max_runs" to the amount of runs you want to calculate.
 *  This Mode ignores the precision parameter.   
 *
 */
void find_root_with_bisection(double interval_start, double interval_end, double precision, int max_runs)
{
  double current_precision = interval_end - interval_start;
  double interval_middle = ( interval_end + interval_start ) / 2 ;
  int run = 1;
  
  while( (current_precision > precision) & (run != max_runs) )
  {
    // check in which interval the root is. set the new interval borders
    if( myfunc(interval_start) * myfunc(interval_middle) < 0 ) interval_end = interval_middle; 
    else interval_start = interval_middle;

    // calculate current precision and the new interval middle
    current_precision = interval_end - interval_start; 
    interval_middle = ( interval_end + interval_start ) / 2 ;
    run++;
  }

  printf("Reached precision of %lf after %d runs. Root found at %lf\n", current_precision, run, interval_middle);
  return;
}


int main(void)
{
    double interval_start = 0;
    double interval_end = 1;
    double precision = 0.00000001;
    int    max_runs = 10;

    printf("\nBisection method:\n");
    find_root_with_bisection(interval_start, interval_end, precision, 0);

    printf("\nBisection method (Max Runs %d):\n", max_runs);
    find_root_with_bisection(interval_start, interval_end, precision, max_runs);

    return 0;
}


