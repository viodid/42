/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrace_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:49:13 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/14 16:40:08 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_number(int **matrix, int row_index, int column_index, int *arguments);
int	check_number_final_check(int **matrix, int row_index, int column_index, int *arguments);

void print_matrix(int **matrix, int row, int col, int n, int *args)
{
	int i = 0;
	int j = 0;

	while (i < 4)
	{
		while (j < 4)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("%d\n", check_number(matrix, row, col, args));
	printf("row %d - col %d\n", row, col);
	printf("-----\n");

}

int	**backtrace(int **matrix, int row, int col, int n, int *args)
{
	int i = 0;
	int j = 0;

/* 	while (i < 4)
	{
		while (j < 4)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	} */
/* 	printf("%d\n", check_number(matrix, row, col, args)); */
/* 	printf("%d\n", check_number(matrix, row, col, args));
	printf("row %d - col %d\n", row, col);
	printf("-----\n"); */
	if (n < 1)
	{
		matrix[row][col] = 0;
		if (col == 0 && row > 0)
		{
			backtrace(matrix, row - 1, 3, (matrix[row - 1][3]) - 1, args);
		}
		else if (col == 0 && row == 0)
		{
			return (0);
		}
		else
		{
			backtrace(matrix, row, col - 1, (matrix[row][col - 1]) - 1, args);
		}
	}
	else
	{
		matrix[row][col] = n;
		if (check_number(matrix, row, col, args))
		{
/* 			print_matrix(matrix, row, col, n, args); */
			
			if (n > 1)
				backtrace(matrix, row, col, n - 1, args);
			else
			{
				matrix[row][col] = 0;
				if (col == 0 && row > 0)
				{
					backtrace(matrix, row - 1, 3, (matrix[row - 1][3]) - 1, args);
				}
				else if (col == 0 && row == 0)
				{
					return (0);
				}
				else 
				{
					backtrace(matrix, row, col - 1, (matrix[row][col - 1]) - 1, args);
				}
			}
		}
		else
		{
/* 			print_matrix(matrix, row, col, n, args); */
			if (col == 3 && row < 3)
			{
				//printf("test1");
				backtrace(matrix, row + 1, 0, 4, args);
			}
			else if (col == 3 && row == 3)
			{
				//printf("test2");
				return (matrix);
			}
			else if (col < 3)
			{
				//printf("test3");
				backtrace(matrix, row, col + 1, 4, args);
			}
		}
		return (matrix);
	}
	return (matrix);
}
