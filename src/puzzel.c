#include "sudoku.h"

int read_puzzel(int **puzzel,char *filepath){
        FILE *readfile = fopen(filepath,"r");
        if(readfile == NULL){
                perror("failed to read file \n");
                return 1;
        }
        char line[64];
        int index = 0;
        while(fgets(line,sizeof(line),readfile)){
                printf("the line this time is : %s and index : %d\n",line,index);

                if(index >= 9){
                        break;
                }

                sscanf(line,"%d %d %d  %d %d %d  %d %d %d",
                &puzzel[index][0],
                &puzzel[index][1],
                &puzzel[index][2],
                &puzzel[index][3],
                &puzzel[index][4],
                &puzzel[index][5],
                &puzzel[index][6],
                &puzzel[index][7],
                &puzzel[index][8]);

                index++;
        }
        fclose(readfile);
        return 0;
}

bool solve(int r,int c,int **puzzel){
	//end of grid with no problems
	if(r == 9){
		return true;
	}
	//c exeeded the grid bounds
	else if(c == 9){
		return solve(r+1,0,puzzel);
	}
	//cell used already
	else if(puzzel[r][c] != 0){
		return solve(r,c+1,puzzel);
	}
	//we start from 1 
	//and 9 value is accepted ...
	//took me forever to realize .
	else{
		for(int x = 1;x <= 9 ;x++){
			if(check_valid_number(r,c,x,puzzel)){
				puzzel[r][c] = x;
				if(solve(r,c+1,puzzel)){
					return true;
				}
				puzzel[r][c] = 0;
			}
		}
		return false;
	}
}

bool check_valid_number(int r,int c,int number,int **puzzel){
	//get box number first to use the function
	int bx = BOX_NUMBER(r,c);
	if(!check_box(number,bx,puzzel)){
		return false;
	}
	if(!check_row(number,r,c,puzzel)){
		return false;
	}
	if(!check_col(number,r,c,puzzel)){
		return false;
	}
	return true;
}


bool check_box(int number,int box_number,int **puzzel){
	int r = locate_row(box_number);
	int c = locate_col(box_number);
	for(int i = r; i<r+3; i++){
		for(int j = c; j<c+3 ;j++){
			if(puzzel[i][j] == number){
				return false;
			}
		}
}
	return true;
}

bool check_row(int number,int r,int c,int **puzzel){
	int i;
    for (i = c - 1; i >= 0; --i) {
        if (puzzel[r][i] == number) {
            return false; // Found the number in the row
        }
    }
    
    for (i = c + 1; i < 9; ++i) {
        if (puzzel[r][i] == number) {
            return false; // Found the number in the row
        }
    }
	return true;
}

bool check_col(int number,int r,int c,int **puzzel){
	int i;
    for (i = r - 1; i >= 0; --i) {
        if (puzzel[i][c] == number) {
            return false; // Found the number in the row
        }
    }
    
    for (i = r + 1; i < 9; ++i) {
        if (puzzel[i][c] == number) {
            return false; // Found the number in the row
        }
    }
	return true;
}


int **getpuzzel(){
	int i,j;
	int array[9][9]=
	{
	{0,0,0 ,0,0,0 ,0,5,0},
	{0,9,0 ,0,0,0 ,8,0,0},
	{0,0,1 ,5,0,0 ,9,3,0},
	
	{9,8,0 ,6,0,1 ,3,0,0},
	{0,0,0 ,8,0,2 ,0,0,0},
	{0,0,6 ,7,0,9 ,0,8,1},
	
	{0,3,7 ,0,0,6 ,2,0,0},
	{0,0,4 ,0,0,0 ,0,6,0},
	{0,1,0 ,0,0,0 ,0,0,0},
	
	};
	int **puzzel = (int **)malloc(sizeof(int*)*9);
	for(i=0;i<9;i++){
		puzzel[i] = malloc(sizeof(int)*9);
		for(j=0;j<9;j++){
			puzzel[i][j] = array[i][j];
		}
	}
	return puzzel;
}

void print_puzzel(int **arr){
	int i,j;
	for(i=0;i<9;i++){
		if((i) % 3 == 0){
			printf("\n");
		}
		for(j=0;j<9;j++){
			printf("%d ",arr[i][j]);
			if((j+1) % 3 == 0 ){
				printf("| ");
			}
		}	
		printf("\n");
	}
}

void print_box(int **puzzel,int r,int c){
	for(int i = r; i<r+3; i++){
		for(int j = c; j<c+3 ;j++){
			printf("%d ",puzzel[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
