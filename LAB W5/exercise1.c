#include <stdio.h>
#include <math.h>
//Not usiing ATM: #define getName(var,str) sprintf(str,"%s",#var)

//Using point-by-value in this exercise

int CheckFile(FILE *file, int check){ //Check File exists
	if(file != NULL){
		printf("File opened\n\n");
		check=1;
	}else{
		printf("Could not open file!\n");
		check=0;
	}
	return(check);
}

void WriteFile(FILE *file, int check,FILE *output,int *zone){ //Read the file and write values to an output
	double x,Cp;
	int angle;
	if(check==1){
		
		if(*zone==0){ //If it is first "time" writing
			fprintf(output,"VARIABLES =\"X\"\"Cp\"\n"); //Write this
		}
		
		printf("Input the angle of attack: "); //Input the angle to name the zone precisely
		scanf("%d", &angle);
		fprintf(output,"ZONE T=\"%d degrees\"\n", angle);
		
		while(feof(file)==0){ //While not the end of file
			fscanf(file, "%lf %lf ", &x, &Cp); 	//finput them to x and y respectively
			fprintf(output,"%lf %lf\n",x,Cp);  	//fPrint the x and y variable to the output
		}
		
	fprintf(output,"\n"); //Make a blank line in the output file
	(*zone)++; //Increment by one zone variable
	printf("\n Finished writing values\n");
	fclose(file); //Close file
	}
	
	else{ printf("Not reading an unexistent file\n"); //If did not pass check print error
	}
}

	
int main(){
	FILE *deg5, *deg10, *deg0, *output; //Create filepointers (3 text files)
	int check=0, zone=0;
	//double x,y;
	deg0 = fopen("naca23015_00degs.txt","r"); //Open file and name the file pointer to that file (read only)
	deg5 = fopen("naca23015_05degs.txt","r"); //"" (read only)
	deg10 = fopen("naca23015_10degs.txt","r"); //"" (read only)
	output = fopen("AerofoilForce.plt","a+"); //"" (a+ = open file or create new if nonexistent, only write at the end of file)
	
	check= CheckFile(deg0,check); //Check existence of file
	printf("Check= %d\n",check); 
	printf("\n Zone= %d\n",zone);
	WriteFile(deg0,check, output, &zone); //Write required values from input file (deg0) to the output file while formatting.
	
	
	
	check= CheckFile(deg5,check); //Check existence of file
	printf("Check= %d\n",check);
	printf("\n Zone= %d\n",zone);
	WriteFile(deg5,check, output, &zone); //Write required values from input file (deg5) to the output file while formatting.
	
	check= CheckFile(deg10,check); //Check existence of file
	printf("Check= %d\n",check);
	printf("\n Zone= %d\n",zone);
	WriteFile(deg10,check, output, &zone); //Write required values from input file (deg10) to the output file while formatting.
	
	return(0);
}