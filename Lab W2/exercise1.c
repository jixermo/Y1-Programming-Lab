#include <stdio.h>
#include <math.h>

int main() {

  /* Allocate memory */
  double dynamicPressure, velocity, density;
  
  /* Hard-code a value of density */
  density=1.225; /* "kg/m^3" */
  
  /* Ask user for input value of velocity and read in */
  printf("Input a value for velocity:");
  scanf("%lf", &velocity);
  
  /* Calculate the dynamic pressure */
  dynamicPressure=0.5*density*(pow(velocity,2));
  
  /* Print the dynamic pressure  */
  printf("The dynamic pressure is: %lf \n", dynamicPressure);
  
  return(0);
}
