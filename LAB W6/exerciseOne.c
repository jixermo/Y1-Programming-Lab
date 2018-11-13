#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Using point-by-value in this exercise

int CheckFile(FILE *file){
	int check;//Check File exists
	if(file != NULL){
		printf("File opened\n\n");
		check=1;
	}else{
		printf("Could not open file!\n");
		check=0;
	}
	return(check);
}


int CreateArraySize(FILE *file/*, double **array*/){ //Function to determine array size and create one.
	int i;
	int n=0, ch=0;
	
	while(feof(file)==0){ //Determine array size (how many rows the text file has)
		ch =fgetc(file);
		if(ch == '\n'){
			n++;
		}
	}
	rewind(file);
	return(n);
}


void WriteFile(FILE *file, double array[50][2], int n){ //Read the file and write values (to array) to an output (Array row size totally arbitrary)
	double x,y;
	int i=0,j;
		while(feof(file)==0){
			fscanf(file,"%lf %lf ",&x,&y);
			array[i][0]=x;
			array[i][1]=y;
			printf("%lf   ",array[i][0]);
			printf("%lf",array[i][1]);
			printf("\n");
			i++;
			}
		}

		
double Interpolation(double array[50][2], double angle, int n){ //Function that returns an interpolated calculation (Array row size totally arbitrary)
	
	int i,j,ll,lu;				/*i,j for the for loop; ll, lu are for the storage 
					of lastlower and lastupper row number related to array double.*/
					
	
	double lower[2], upper[2]; //store lower and upper (angle and respective coefficient);
	
	printf("n= %d\n\n",n);
	ll=-1;			//startup value to check if it exists or not;
	lu=-1;			//startup value to check if it exists or not;
	
	for(i=0;i<n;i++){			//loop for reading the array in i,j order;
		printf("%lf   ",array[i][0]);
		printf("%lf",array[i][1]);
		printf("\n");
		
		if(array[i][0]<=angle){ //Check for the latest lower point comparing to last lower and angle.
			if(ll==-1){
				ll=i; 	//stores the position in array of the last lower (first time);
			}
			else if(array[i][0]>array[ll][0]){
				ll=i;	//stores the position in array of the last lower (compares to the last one);
			}
		}
		if(array[i][0]>=angle){ //Check for the latest higher point comparing to last upper and angle.
			if(lu==-1){
				lu=i;	//stores the position in array of the last upper (first time);
			}
			else if(array[i][0]<array[lu][0]){
				lu=i;	//stores the position in array of the last upper;
			}
		}
		printf("Lower: %lf  Upper: %lf\n\n",array[ll][0], array[lu][0]); //check for correct lower and upper boundaries values
		}
	
	if(ll==-1 || lu==-1){
		printf("There is no lower and/or upper value for the angle of attack\n");  //aborts program because lack of upper or lower boundary.
		abort();
	}
	
	double a,b, LC; //define variables and calculate the linear interpolation;
	
	if(ll==lu){	//special case when ll==lu (returns LC as row lu of array);
		printf("\nlower == upper boundary\n");
			LC=array[lu][1];
	}else{
		a=(array[lu][1]-array[ll][1])/(array[lu][0]-array[ll][0]);
		b=array[ll][1]-(a*array[ll][0]);
		LC=(a*angle)+b;
	}
	
	return(LC); //returns Lift Coefficient value;
}



int main(){
	FILE *fid1; //Create filepointers (1 text file)
	fid1= fopen("liftcoeff.txt","r"); //opens the file
	
	if(CheckFile(fid1)==1){ 		//if file
		double array[50][2], angleattack, result;  //define variables (Array row size totally arbitrary)
		printf("fid1 angle of attack: ");
		scanf("%lf",&angleattack);  //input angleattack from user
		
		int n;
		n=CreateArraySize(fid1); //checks what should the array size be relative to the rows in fid1;
		WriteFile(fid1, array,n); //prints arrays values (taken from fid1);
		fclose(fid1); //Close fid1;
		printf("\nFile Closed\n");
		
		result=Interpolation(array,angleattack,n); //results defined as the return value (Lift Coefficient) from Interpolation calculation
		printf("\n\n");
		printf("The lift coefficient is: %lf\n",result); //prints result;
	}else{
		printf("File does not exit, aborting...\n");
		abort();
	}
	return(0);
}