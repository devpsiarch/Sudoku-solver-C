#include "sudoku.h"
#include "write_solution.h"

int main(void){
	int **puzzel = getpuzzel();
	print_puzzel(puzzel);
	if(!read_puzzel(puzzel,"puzzel.txt")){
		printf("reading puzzel file \n\n");
	}
	else{
		printf("failed to read the puzzel file\n\n");
		return 1;
	}	
	if(solve(0,0,puzzel)){
		printf("puzzel solved !!\n");
		print_puzzel(puzzel);
	}else{
		printf("enable to solve the puzzel :(\n");
		print_puzzel(puzzel);
	}
	write_file(puzzel,"solution/solved.txt");
	free(puzzel);	
	return 0;
}
