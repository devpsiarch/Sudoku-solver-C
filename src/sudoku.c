#include "sudoku.h"


int main(void){
	int **puzzel = getpuzzel();
	print_puzzel(puzzel);
	
	if(solve(0,0,puzzel)){
		printf("puzzel solved !!\n");
		print_puzzel(puzzel);
	}else{
		printf("enable to solve the puzzel :(\n");
		print_puzzel(puzzel);
	}
	
	return 0;
}
