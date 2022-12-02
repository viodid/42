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
int	check_constraints_row_final_check(int *row, int row_index, int column_index, int *arguments);
int	check_constraints_col_final_check(int *column, int row_index, int column_index, int *arguments);

int	check_number_final_check(int **matrix, int row_index, int column_index, int *arguments)
{
	int	*row;
	int	*column;
	int	size;

	size = 4;
	row = get_row(matrix, row_index);
	column = get_column(matrix, column_index, size);
	if (check_constraints_row_final_check(row, row_index, column_index, arguments) 
	|| check_constraints_col_final_check(column, row_index, column_index, arguments))
	{
		return (1);
	}
	return (0);
}
