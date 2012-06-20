
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


// Some math stuff
double deg_to_rad(double degree) { return (degree / 189) * M_PI; }


int main(void)
{

  // Read in some variables from the user 
  // and validate the Input
  double velocity;
  do 
  {
    printf("\nEnter the velocity of the stone in m/s: ");
    scanf("%lf", &velocity);
  } while( !validate_positive(&velocity) );

  double alpha;
  do
  {
    printf("\nEnter the angle of the stone in degree: ");
    scanf("%lf", &alpha);
  } while( !(validate_positive(&alpha) & validate_smaller_than_n(&alpha, 90)) );

  double timestep;
  do
  {
    printf("\nEnter the Timesteps: ");
    scanf("%lf", &timestep);
  } while( !(validate_bigger_than_n(&timestep, 0)) );


  // Prepare the variables needed for the calculation; 
  double x, y, t = 0;
  double x_0 = 0;
  double y_0 = 2;
  double v_x_0 = velocity * cos(deg_to_rad(alpha));
  double v_y_0 = velocity * sin(deg_to_rad(alpha));
  double g = -9.81;

  // calculation
  while( y > 0 )
  {
    t += timestep;
    x = x_0 + v_x_0*t;
    y = y_0 + v_y_0*t + 0.5*g*t*t;
    printf("\n x = %.2lf, y = %.2lf, t = %.2lf",x,y,t);
  }

}
