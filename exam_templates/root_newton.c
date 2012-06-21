
#include <stdio.h>
#include <math.h>


double myfunc(double x)
{
  return exp(-x) - x;
}


double myfunc_der(double x)
{
  return -exp(-x) - 1;
}


/** Finds one root in the given interval with the newton-raphson method.
 * 
 *  Precision Mode:
 *  Set "max_runs" to 0 if you want to run until the desired precision is reached
 *
 *  Max Run Mode:
 *  Set "max_runs" to the amount of runs you want to calculate.
 *  This Mode ignores the precision parameter.   
 *
 */
void find_root_with_newton(double interval_start, double interval_end, double precision, int max_runs)
{
  double current_precision = interval_end - interval_start;
  int run = 1;
  
  while( (current_precision > precision) & (run != max_runs) )
  {
    double old_interval_end = interval_end;

    interval_end -= myfunc(interval_end) / myfunc_der(interval_end);
    
    current_precision = fabs( old_interval_end - interval_end ) / 2.0;
    run++;
  }

  printf("Reached precision of %lf after %d runs. Root found at %lf\n", current_precision, run, interval_end);
  return;
}


int main(void)
{
    double interval_start = 0;
    double interval_end = 1;
    double precision = 0.00000001;
    int    max_runs = 10;

    printf("\nNewton method:\n");
    find_root_with_newton(interval_start, interval_end, precision, 0);

    printf("\nNewton method (Max Runs %d):\n", max_runs);
    find_root_with_newton(interval_start, interval_end, precision, max_runs);

    return 0;
}


