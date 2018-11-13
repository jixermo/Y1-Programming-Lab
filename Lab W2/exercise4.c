#include <stdio.h>
#include <math.h>

int main() {

  /* Allocate memory */
  double dynamicPressure, velocity, density, angle, Pi, lift;
  
  /* Hard-code a value of density */
  density=1.225; /* "kg/m^3" */
  
  /* Calculate a value for PI */
  Pi= 4.0*atan(1.0);
  
  /* Ask user for input value of velocity and angle of incidence and read in */
  printf("Input a value for velocity:");
  scanf("%lf", &velocity);
  
  printf("Input a value for the angle of incidence (in degrees): ");
  scanf("%lf", &angle);
  
  /* Calculate the dynamic pressure */
  dynamicPressure=(0.5)*density*(pow(velocity, 2.0 ));
  
  /* Convert angle from degrees to radians */
  angle= angle/180*Pi;
  
  /* Print the dynamic pressure  */
  printf("The dynamic pressure is: %lf \n", dynamicPressure);
  
  /* Print the angle (in radians)  */
  printf("The angle of incidence is (in radians): %lf \n \n", angle);
  
  /* Calculate the lift  */
  lift= dynamicPressure*2*Pi*angle;
  
  /* Print the total lift  */
  printf("The total lift is: %lf \n", lift);
  
  return(0);
}
