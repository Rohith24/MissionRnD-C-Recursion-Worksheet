/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiral_roll(int *rows, int *columns, int **input_array,int *currow,int *curcolumn,int *a,int *index){
	int i, k = *currow, l = *curcolumn;
	if (k >= *rows || l >= *columns){
		return;
	}
	for (i = l; i < *columns; ++i)
	{
		a[*index] = input_array[k][i];
		*index = *index + 1;
	}
	k++;

	for (i = k; i < *rows; ++i)
	{
		a[*index] = input_array[i][*columns - 1];
		*index = *index + 1;
	}
	*columns=*columns-1;

	if (k < *rows)
	{
		for (i = *columns - 1; i >= l; --i)
		{
			a[*index] = input_array[*rows - 1][i];
			*index = *index + 1;
		}
		*rows=*rows-1;
	}
	else
	{
		return;
	}

	if (l < *columns)
	{
		for (i = *rows - 1; i >= k; --i)
		{
			a[*index] = input_array[i][l];
			*index = *index + 1;
		}
		l++;
	}
	else
	{
		return;
	}
	*currow = k;
	*curcolumn = l;
	spiral_roll(rows, columns, input_array, currow, curcolumn, a, index);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int index = 0, currow = 0, curcolumn=0;
	int *a=NULL;
	a = (int *)malloc(sizeof(int)*(rows*columns));
	spiral_roll(&rows, &columns, input_array, &currow, &curcolumn, a, &index);
	return a;
}
