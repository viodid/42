/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:00:56 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/13 19:03:53 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

int	*get_row(int **matrix, int row_index);
int	*get_column(int **matrix, int column_index, int size);
int	check_constraints_row(int *row, int row_index, int column_index, int *arguments);
int	check_constraints_col(int *column, int row_index, int column_index, int *arguments);

int	check_number(int **matrix, int row_index, int column_index, int *arguments)
{
	int	*row;
	int	*column;
	int	size;

	size = 4;
	row = get_row(matrix, row_index);
	column = get_column(matrix, column_index, size);
	if (check_constraints_row(row, row_index, column_index, arguments) 
	|| check_constraints_col(column, row_index, column_index, arguments))
	{
		return (1);
	}
	return (0);
}

int	*get_row(int **matrix, int row_index)
{
	return &matrix[row_index][0];
}

int	*get_column(int **matrix, int column_index, int size)
{
	int	*row_output;
	int	*start_row_output;
	int i;

	row_output = malloc(sizeof(int) * size);
	start_row_output = row_output;
	if (row_output == NULL)
	{
		free(row_output);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		*row_output = matrix[i][column_index];
		row_output++;
		i++;
	}
	return start_row_output;
}
