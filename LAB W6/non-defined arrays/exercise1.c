#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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


int CreateArraySize(FILE *file/*, double **array*/){ //Function to determine array size and create one.
	int i;
	int n=0, ch=0;
	
	while(feof(file)==0){ //Determine array size (how many rows the text file has)
		ch =fgetc(file);
		if(ch == '\n'){
			n++;
		}
	}
	return(n);
}


void WriteFile(FILE *file, int check, double **array){ //Read the file and write values to an output
	double x,y;
	int i,j,n;
	if(check==1){
		n=CreateArraySize(file);
		array=(double **)calloc(n, sizeof(int*)); //Determine number of rows and columns for array
		for(i=0;i<2;i++){
			array[i]= (double *)calloc(2,sizeof(int));
		}
		rewind(file);
		
		//while(feof(file)==0){ //While not the end of file
			 //finput them to x and y respectively
			for(i=0;i<n;i++){
				for(j=0;j<2;j++){
					fscanf(file, "%f ",&x);
					printf("%f\n",x);
					array[i][j]=x;
					printf("%f\t", array[i][j]);
				}
				printf("\n");
			}
		//}
	printf("\nFinished writing values\n");
	fclose(file); //Close file
	}
	
	else{ printf("Not reading an unexistent file\n"); //If did not pass check print error
	}
}


	
int main(){
	FILE *input; //Create filepointers (3 text files)
	int n;
	int check=0, zone=0;
	double **array;
	//double x,y;
	//deg0 = fopen("naca23015_00degs.txt","r"); //Open file and name the file pointer to that file (read only)
	input = fopen("liftcoeff.txt","r");
	
	check= CheckFile(input,check); //Check existence of file
	printf("Check= %d\n",check);
	
	n=CreateArraySize(input);
	printf("%d\n", n);
	
	WriteFile(input, check, array);
	//WriteFile(input,check, array); //Write required values from input file (deg0) to the output file while formatting.

	
	return(0);
}