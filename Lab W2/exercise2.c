#include <stdio.h>
#include <math.h>

int main() {

  /* Allocate memory */
  double dynamicPressure, velocity, density, angle;
  
  /* Hard-code a value of density */
  density=1.225; /* "kg/m^3" */
  
  /* Ask user for input value of velocity and angle of incidence and read in */
  printf("Input a value for velocity:");
  scanf("%lf", &velocity);
  
  printf("Input a value for the angle of incidence (in degrees): ");
  scanf("%lf", &angle);
  
  /* Calculate the dynamic pressure */
  dynamicPressure=0.5*density*(pow(velocity,2));
  
  /* Print the dynamic pressure  */
  printf("The dynamic pressure is: %lf \n", dynamicPressure);
  
  /* Print the dynamic pressure  */
  printf("The angle of incidence is: %lf \n", angle);
  
  return(0);
}
