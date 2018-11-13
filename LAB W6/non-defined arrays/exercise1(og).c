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


void WriteFile(FILE *file, int check, double array[50][2]){ //Read the file and write values to an output
	double x,y;
	int i,j,n;
	check = CheckFile(file,check);
	if(check==1){
		n=CreateArraySize(file);
		printf("%d\n",n);
		while(feof(file)==0){ //While not the end of file
			 //finput them to x and y respectively
			fscanf(file, "%lf &lf",&x, &y);
			for(i=0;i<n;i++){
					
				for(j=0;j<2;j++){
					if(j==0){
						array[i][j]=x;
						printf("%f\t",array[i][j]);
					}else{
						array[i][j]=y;
						printf("%f\t",array[i][j]);
					}
				}
				printf("\n");
			}
		//}
	printf("\nFinished writing values\n");
	fclose(file); //Close file
		}
	}
	else{ printf("Not reading an unexistent file\n"); //If did not pass check print error
	}
}


	
int main(){
	FILE *input; //Create filepointers (1 text file)
	input= fopen("liftcoeff.txt","r");
	double array[50][2];
	int check=0, zone=0;
	WriteFile(input, check, array);
	printf("Finished every\n");
	return(0);
}