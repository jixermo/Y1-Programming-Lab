#include <stdio.h>
#include <math.h>
int main(){
	/* Allocate memory */
	double N, x0, error, fx, dfx;
	int tmax,i;
	
	/* Request input for N check if it is positive,
	otherwise replace N by the absolute value (and display a warning)*/
	printf("Input a number you wish to find the square-root of:");
	scanf("%lf", &N);
	if(N<0){
		printf("This program only calculates real roots.\nWe are going to use the absoulte value of your input.\n" );
		N=-N;
	}
	printf("%lf\n",N);
	
	/* Determine maximum tries */
	tmax=1000;
	
	/* Determine error tolerance */
	error=0.5;
	
	/* Determine first guess */
	x0=2;
	/* Prepare for the final printout */
	printf("------------------------------------------------\n t      x(t)     f(x)      f'(x)     x(t+1)\n------------------------------------------------\n");
	
	/* Estimate the square-root with Newton-Raphson method
	(with a maximum of tmax iterations)*/
	for(i=0; i<tmax; i++){
		printf("%2d  %8.6lf",i+1, x0);
		x0=x0-(pow(x0,2.0)-N)/(2*x0); //function for the estimation;
		printf("  %8.6lf  %8.6lf  %8.6lf\n",pow(x0,2.0)-N,(2*x0),x0);
	if(pow(x0,2.0)-N<error){
			break;
		}
	}
	
	printf("------------------------------------------------\n The square-root of N is: %lf\n",x0);
	
	
}