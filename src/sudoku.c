#include "sudoku.h"


int main(void){
	int **puzzel = getpuzzel();
	print_puzzel(puzzel);

	if(check_valid_number(0,0,3,puzzel)){
		printf("the number is valid for this possition!\n");
	}
	else{
		printf("number not valid \n");
	}
	return 0;
}
