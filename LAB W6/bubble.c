#include<stdio.h>

int main () {

  FILE *fid;
  int list[15], i, j, nlist=15, swapped, x1, x2;

  /* Read in list */
  fid=fopen("list","r");
  for (i=0; i<nlist; i++) {
    fscanf(fid,"%i",&list[i]);
         //printf("%3i",list[i]);
  }
  fclose(fid);
       printf("\n");

  /* keep swapping until no swap has happened */
  do {

    swapped=0;

    /* loop over all numbers in list */
    for (i=0; i<nlist-1; i++) {
       x1=list[i]; x2=list[i+1];
       if (x2 > x1) {
          list[i]=x2;
          list[i+1]=x1;
          swapped=1;
       }

       /* print list */
       for (j=0; j<nlist; j++) {
         printf("%3i",list[j]);
       }
       printf("\n");

    }


  } while (swapped == 1);

  return(0);

}

