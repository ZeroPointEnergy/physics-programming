
#include <stdio.h>
#include <math.h>


// Some validation functions 
int true = 1;
int false = 0;

int validate_bigger_than_n(double *var, double n)
{
  if(*var > n) return true;
  printf("\nVALIDATION ERROR: Has to be bigger than %lf\n",n);
  return false;
}

int validate_smaller_than_n(double *var, double n)
{
  if(*var < n) return true;
  printf("\nVALIDATION ERROR: Has to be smaller than %lf\n",n);
  return false;
}

int validate_positive(double *var)
{
  if(*var >= 0) return true;
  printf("\nVALIDATION ERROR: Has to be positive\n");
  return false;
}

int validate_in_interval(int *var, int interval_start, int interval_end)
{
  if( interval_start <= *var <= interval_end ) return true; 
  printf("\nVALIDATION ERROR: Should be in the interval [%d,%d]\n",interval_start, interval_end);
  return false;
}


double myfunc(double x, double y)
{
  return -x*x*y*y;
}

void differential_equation_euler(FILE *output_file, double interval_start, double interval_end, double initial_y, double stepsize)
{
  // set initial conditions
  double x = interval_start;
  double y = initial_y;
  
  // write initial stuff to the file
  fprintf(output_file, "Result table for the euler method:\n");
  fprintf(output_file, "|     x    |     y    |\n");
  fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);

  // calculate the amount of steps
  int steps = ceil( fabs(interval_end - interval_start) / stepsize );

  // the euler method
  int i;
  for (i = 0; i < steps; i++) {
    y += stepsize * myfunc(x, y);
    x += stepsize;
    fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);
  }
}


void differential_equation_runge_kutta_ii(FILE *output_file, double interval_start, double interval_end, double initial_y, double stepsize)
{
  // set initial conditions
  double x = interval_start;
  double y = initial_y;
  
  // write initial stuff to the file
  fprintf(output_file, "Result table for the runge_kutta_ii method:\n");
  fprintf(output_file, "|     x    |     y    |\n");
  fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);

  // calculate the amount of steps
  int steps = ceil( fabs(interval_end - interval_start) / stepsize );

  // the euler method
  int i; double k_1, k_2;
  for (i = 0; i < steps; i++) {
    k_1 = stepsize * myfunc(x               , y          );
    k_2 = stepsize * myfunc(x + 0.5*stepsize, y + 0.5*k_1);

    y += k_2;
    x += stepsize;
    fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);
  }
}


void differential_equation_runge_kutta_iv(FILE *output_file, double interval_start, double interval_end, double initial_y, double stepsize)
{
  // set initial conditions
  double x = interval_start;
  double y = initial_y;
  
  // write initial stuff to the file
  fprintf(output_file, "Result table for the runge_kutta_ii method:\n");
  fprintf(output_file, "|     x    |     y    |\n");
  fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);

  // calculate the amount of steps
  int steps = ceil( fabs(interval_end - interval_start) / stepsize );

  // the euler method
  int i; double k_1, k_2, k_3, k_4;
  for (i = 0; i < steps; i++) {
    k_1 = stepsize * myfunc(x               , y           );
    k_2 = stepsize * myfunc(x + 0.5*stepsize, y + 0.5*k_1 );
    k_3 = stepsize * myfunc(x + 0.5*stepsize, y + 0.5*k_2 );
    k_4 = stepsize * myfunc(x + stepsize    , y + k_2     );

    y += k_1 / 6 + k_2 / 3 + k_3 / 3 + k_4 / 6;
    x += stepsize;
    fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);
  }
}


void exact_solution(FILE *output_file, double interval_start, double interval_end, double initial_y, double stepsize)
{
  // set initial conditions
  double x = interval_start;
  double y = initial_y;
  
  // write initial stuff to the file
  fprintf(output_file, "Result table for the exact solution:\n");
  fprintf(output_file, "|     x    |     y    |\n");
  fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);

  // calculate the amount of steps
  int steps = ceil( fabs(interval_end - interval_start) / stepsize );

  // create the data table for the exact solution
  int i;
  for (i = 0; i < steps; i++) {
    x += stepsize;
    y = 3 / ( 3 + x*x*x );
    fprintf(output_file, "| %.6lf | %.6lf |\n", x, y);
  }
}

int main(void)
{

  // Read in some variables from the user 
  // and validate the Input
  int method;
  do 
  {
    printf("\nchose the method for the calculation: 1) Euler, 2) Runge-Kutta II, 3) Runge-Kutta IV 4) Exact Solution: ");
    scanf("%d", &method);
  } while( !validate_in_interval(&method, 1, 4) );

  double interval_start;
  do
  {
    printf("\nEnter the left interval border: ");
    scanf("%lf", &interval_start);
  } while(0);

  double interval_end;
  do
  {
    printf("\nEnter the right interval border: ");
    scanf("%lf", &interval_end);
  } while( !(validate_bigger_than_n(&interval_end, interval_start)) );

  double stepsize;
  do
  {
    printf("\nEnter the stepsize: ");
    scanf("%lf", &stepsize);
  } while( !(validate_positive(&stepsize)) );

  
  FILE *output_file = fopen("excercise_11.1_data.txt", "w");
  
  // Call the method that was chosen by the user input
  switch(method)
  {
    case 1:
      differential_equation_euler(output_file, interval_start, interval_end, 1, stepsize);
    break;

    case 2:
      differential_equation_runge_kutta_ii(output_file, interval_start, interval_end, 1, stepsize);
    break;

    case 3:
      differential_equation_runge_kutta_iv(output_file, interval_start, interval_end, 1, stepsize);
    break;

    case 4:
      exact_solution(output_file, interval_start, interval_end, 1, stepsize);
    break;
  }

  fclose(output_file);

  return 0;
}
