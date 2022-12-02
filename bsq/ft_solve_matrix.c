/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:36:27 by rsanz-de          #+#    #+#             */
/*   Updated: 2022/11/23 11:36:32 by rsanz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	columns_calc(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[0][i] != '\0')
	{
		i++;
	}
	if (i > 0)
		i--;
	return (i);
}

int	rows_calc(int **matrix)
{
	int	i;

	i = 0;
	printf("its rows2\n");
	printf("%d\n", i);
	while (matrix[i][0] != '\0')
	{
		printf("%d\n", i);
		i++;
	}
	printf("its rows3\n");
	if (i > 0)
		i--;
	return (i);
}

int	ft_min_leftdown(int **matrix, int row, int col)
{
	int	min;
	int	right;
	int	right_down;
	int	down;

	right = matrix[row][col + 1];
	right_down = matrix[row + 1][col + 1];
	down = matrix[row + 1][col];
	min = right;
	if (min > right_down)
		min = right_down;
	if (min > down)
		min = down;
	return (min);
}

int	ft_solve_matrix(int **matrix)
{
	int	rows;
	int	columns;
	int	row;
	int	col;

	columns = columns_calc(matrix);
	col = columns - 1;
	rows = rows_calc(matrix);
	row = rows - 1;
	while (row >= 0)
	{
		col = columns - 1;
		while (col >= 0)
		{
			if (matrix[row][col] == 1)
				matrix[row][col] = ft_min_leftdown(matrix, row, col) + 1;
			col--;
		}
		row--;
	}
	return (0);
}

void	print_matrix(int **matrix)
{
	int col;
	int row;
	int rows;
	int columns;

	col = 0;
	row = 0;
	printf("its ok7 \n");
	rows = rows_calc(matrix);
	printf("its ok8 \n");
	columns = columns_calc(matrix);
	printf("its ok9 \n");
	while (row <= rows)
	{
		col = 0;
		while (col <= columns)
		{
			printf("%d ", matrix[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

int generate_matrix(int **matrix, int row_gen, int col_gen)
{
	int i;
	int col;
	int row;

	i = 0;
	col = 0;
	row = 0;
	printf("%d %d\n", row_gen, col_gen);
	matrix = malloc (sizeof(int *) * (row_gen + 3));
	if(!matrix)
		return (1);
	printf("its ok2 \n");
	while (i < row_gen)
	{
		matrix[i] = malloc (sizeof(int) * (col_gen + 3));
		i++;
	}
	printf("its ok3 \n");
	while (row < row_gen)
	{
		col=0;
		while (col < col_gen)
		{
			matrix[row][col] = 1;
			col++;
		}
		row++;
	}
	printf("its ok4 \n");
	return (0);
}

int main (void)
{
	int **matrix;
	int	row_gen;
	int	col_gen;

	row_gen = 5;
	col_gen = 5;
	printf("its ok\n");
	if(generate_matrix(matrix, row_gen, col_gen) == 1)
		return 1;
	printf("its ok5\n");
	print_matrix(matrix);
	printf("its ok10\n");

	matrix[1][1] = 0;
	matrix[2][2] = 0;

	print_matrix(matrix);
	//printf("after filling matrix l.140\n");
	//printf("rows: %d\n", rows);
	//printf("columns: %d\n", columns);
	ft_solve_matrix(matrix);
	//printf("after solving matrix l.146\n");
	print_matrix(matrix);
	//printf("printed matrix\n");
	//printf("%d\n", matrix[3][0]);
	//printf("%d\n", ft_min_leftdown(matrix, 0, 1));

	exit (0);
}