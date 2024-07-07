#ifndef SUDOKU_H_
#define SUDOKU_H_

#define locate_row(x) (x/3)*3
#define locate_col(x) (x%3)*3
#define BOX_NUMBER(row, col) (((row) / 3) * 3 + ((col) / 3))

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_valid_number(int r,int c,int number,int **puzzel);
bool check_box(int number,int box_number,int **puzzel);
bool check_row(int number,int r,int c,int **puzzel);
bool check_col(int number,int r,int c,int **puzzel);

int **getpuzzel();

void print_puzzel(int **arr);
void print_box(int **puzzel,int r,int c); 
#endif
