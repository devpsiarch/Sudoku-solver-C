#include "write_solution.h"

void write_file(int **puzzel,char *filename){
	FILE *fptr;
	int i,j;
	fptr = fopen(filename,"w");
	
	for(i = 0;i<9;i++){
		for(j=0;j<9;j++){
			fprintf(fptr,"%d",puzzel[i][j]);
		}
	}
	//so the python function know when to stop pressing
	fprintf(fptr,"X");
	fclose(fptr);
}
