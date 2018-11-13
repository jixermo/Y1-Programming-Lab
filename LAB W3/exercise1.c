#include <stdio.h>
#include <math.h>
int main(){
	/* Allocate memory */
	double N, x0, tmax, error;
	
	/* Request input for N check if it is positive,
	otherwise replace N by the absolute value (and display a warning)*/
	printf("Input a number you wish to find the square-root of:");
	scanf("%lf", &N);
	if(N<0){
		printf("This program only calculates real roots.\nWe are going to use the absoulte value of your input.\n" );
		N=-N;
	}
	printf("%lf",N);
	
}