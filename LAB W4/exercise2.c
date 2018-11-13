#include <stdio.h>
#include <math.h>

double SecondMomentArea(double c, double t){ //Function to calculate the Second Moment of Area
	double I;
	I=(c*pow(t,3.0))/12;
	return(I);
}

double LoadingPerUnitSpan(double wing, double fuel,double semispan ){ //Function to calculate the Loading Per Unit Span
	double q;
	q= (wing + fuel)/semispan;
	return(q);
}

double TipDeflection(double Wwing, double Wfuel, double s, double E, double c, double t){ //Function to calculate the Tip Deflection
	double TipD;
	TipD= (LoadingPerUnitSpan(Wwing, Wfuel,s) * pow(s,4.0))/(8*E*SecondMomentArea(c,t));
	return(TipD);
}

/*Evaulating Wtest using bisection method to obtain Wfuel*/

double EvaluateWtest(double U, double L, double Wwing, double Wfuel, double s, double E, double c, double t, double h, double error){
	double Wtest;
	int exit=0;
	while(exit!=1){
		Wtest=(U+L)/2;
		if(TipDeflection(Wwing,Wtest,s,E,c,t) > (h+error)){
			printf("%5.2lf %7.2lf  %6.2lf  %5.4lf\n", L, U, Wtest, TipDeflection(Wwing,Wtest,s,E,c,t)); //Print the values in each reiteration
			U=Wtest;
			
		} else if(TipDeflection(Wwing,Wtest,s,E,c,t) < (h-error)){
			printf("%5.2lf %7.2lf  %6.2lf  %5.4lf\n", L, U, Wtest, TipDeflection(Wwing,Wtest,s,E,c,t)); //Print the values in each reiteration
			L=Wtest;
		}else{
			printf("%5.2lf %7.2lf  %6.2lf  %5.4lf\n", L, U, Wtest, TipDeflection(Wwing,Wtest,s,E,c,t)); //Print the values in each reiteration
			Wfuel=Wtest;
			exit=1;
		}
	}
	printf("\n");
	return(Wfuel);
}


int main() {
	
	/*Hard coding values*/
	double t, c, s, E,WeightW, HeightW,Wfuel,Wtest,U, L, error;
	int exit=0;
	t=0.07;
	c=0.6;
	s=13.5;
	E=69*pow(10,9);
	WeightW=1150;
	HeightW=0.5;
	U=10000;
	L=0;
	error=1*pow(10,-4);
	
	//Evalute Wtest to obtain Wfuel & Print the values in each reiteration
	printf("   Lower   Upper   Wfuel   Def.\n");
	printf(" -------------------------------\n");
	Wfuel= EvaluateWtest(U,L,WeightW,Wfuel,s,E,c,t,HeightW,error);
	printf("Weight of fuel is  %3.2lfN with %5.4lfm deflection\n", Wfuel, TipDeflection(WeightW,Wfuel,s,E,c,t));
}