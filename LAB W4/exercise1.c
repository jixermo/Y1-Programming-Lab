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

int main() {
	
	/*Hard coding values*/
	double t, c, s, E,WeightW, HeightW, fuel;
	t=0.07;
	c=0.6;
	s=13.5;
	E=69*pow(10,9);
	WeightW=1150;
	HeightW=0.5;
	fuel=0;
	
	printf("%10.8lf\n", SecondMomentArea(c,t));
	printf("%10.8lf\n", LoadingPerUnitSpan(WeightW,fuel,s));
	printf("%10.8lf\n", TipDeflection(WeightW,fuel,s,E,c,t));
}

