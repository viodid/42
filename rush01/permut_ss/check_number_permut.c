/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_permut.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:28:45 by rsanz-de          #+#    #+#             */
/*   Updated: 2022/11/13 23:17:50 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int	**backtrace_permut(int **matrix, int row, int i, int *args, int **permutations);

int check_column( int *column)
{
	int key;
	int j;
	int counter = 0;
	int size = 4;
	int aux_arr[size];

	while (counter < size)
	{
		aux_arr[counter] = column[counter];
		counter++;
	}
	counter = 0;

	while (counter < size)
	{
		key = *(aux_arr + counter);
		j = counter - 1;
		while (j >= 0 && *(aux_arr + j) > key)
		{
			*(aux_arr + j + 1) = *(aux_arr + j);
			j--;
		}
		*(aux_arr + j + 1) = key;
		counter++;
	}
	counter = 1;
	while(counter < size)
	{
		if((aux_arr[counter] != 0) && aux_arr[counter-1] == aux_arr[counter])
			return(-1);
		counter ++;
	}
	return (1);
}

int mayor_num(int prev, int act)
{
	if(prev > act)
		return prev;
	else if(prev < act)
	{
		return act;
	}
	return (0);
}

int mayor_num_cont(int prev, int act, int counter)
{
	if(prev > act)
		return counter;
	else if(prev < act)
	{
		counter ++;
		return counter;
	}
	return (0);
}


int check_matrix_rows (int *input[], int *matrix[], int row)
{
	int column;
	int max_row_temp [8];
	int counter_row [8] =  {1,1,1,1,1,1,1,1};

	column=1;
	max_row_temp [row]=matrix [row][0];
	max_row_temp [4+row]==matrix [row][3];
	while(column <4)
	{
		max_row_temp [row]= mayor_num(max_row_temp [row], matrix [row][column]);
		counter_row [row] = mayor_num_cont(max_row_temp [row], matrix [row][column], counter_row [row]);
		max_row_temp [4+row]= mayor_num(max_row_temp [4+row], matrix [row][3-(column)]);
		counter_row [4+row] = mayor_num_cont(max_row_temp [4+row], matrix [row][3-(column)], counter_row [row+4]);
		column++;
	}
	if ((input[8+row]!=counter_row [row]) && (input[12+row] != counter_row [row+4]))
		return 0;
	return 1;
}

int check_matrix_columns (int *input[], int *matrix[])
{
	int row;
	int column;
	int max_column_temp [8];
	int max_row_temp [8];
	int counter_col [8]=  {1,1,1,1,1,1,1,1};

	row=1;
	column=0;
	max_column_temp [column]=matrix [0][column];
	max_column_temp [4+column]=matrix [3][column];
	while(column <4 && matrix [3][0] != 0)
	{
		while(row <4)
		{
			max_column_temp [column]= mayor_num(max_column_temp [column], matrix [row][column]);
			counter_col [column] = mayor_num_cont(max_column_temp [column], matrix [row][column], counter_col [column]);
			max_column_temp [4+column] = mayor_num(max_column_temp [4+column], matrix [3-(row)][column]);
			counter_col [4+column] = mayor_num_cont(max_column_temp [4+column], matrix [3-(row)][column], counter_col [column+4]);
			row++;
		}
		if ((input [column]!=counter_col [column]) && (max_row_temp [4+column] != counter_col [column+4]))
			return 0;
		column++;
	}
	return 1;
}

int check_matrix_rep ( int **matrix, int row)
{
	int column;

	column=0;
	while(column <4)
	{
		if (check_column(/* *matrix, column*/ get_row(column)) == -1)
			return (0);
		column++;
	}
	return 1;
}

int check_number_permut(int **matrix, int row_index, int *arguments)
{
	int matrix_rows;
	int matrix_columns;
	int matrix_rep;

	matrix_rows=check_matrix_rows (*arguments, *matrix, row_index);
	matrix_columns=check_matrix_columns (*arguments, *matrix);
	matrix_rep=check_matrix_rep ( *matrix, row_index);
	if ((matrix_rows == 1) && (matrix_columns == 1) && (matrix_rep==1))
		return (1);
	else	return (0);
}

/* int main(int argc, char *argv[])
{
	int matrix [25]={1234 , 1243 , 1324 , 1342 , 1423 , 1432 , 2134 , 2143 , 2314 , 2341 , 2413 , 2431 
	, 3124 , 3142 , 3214 , 3241 , 3412 , 3421 , 4123 , 4132 , 4213 , 4231 , 4312 , 4321, 0000};	
} */