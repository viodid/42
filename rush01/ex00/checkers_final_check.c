/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:33:47 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/13 23:09:26 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

int	*parse_arguments(char *numbers, int size);
int	*create_numbers(int size);
int check_repetition( int *column);
int	check_left_max(int *row, int row_index);
int check_right_max(int *row, int row_index);
int	check_up_max(int *column, int row_index);
int	check_down_max(int *column, int column_index);


int	check_constraints_row_final_check(int *row, int row_index, int col_index, int *arguments)
{
	int	max_left;
	int max_right;
	int	constraint_left;
	int	constraint_right;

	max_left = check_left_max(row, col_index);
	max_right = check_right_max(row, col_index);
	constraint_left = arguments[row_index + 8];
	constraint_right = arguments[row_index + 12];
	printf("max_left: %d - constrain%d\nmax_right:%d - constrain%d\n", max_left, constraint_left, max_right, constraint_right);
	if (check_repetition(row))
	{
		return (1);
	}
	if (max_left > constraint_left || max_right > constraint_right)
	{
		return (1);
	}
	return (0);
}

int	check_constraints_col_final_check(int *col, int row_index, int col_index, int *arguments)
{
	int	max_up;
	int max_down;
	int	constraint_up;
	int	constraint_down;

	max_up = check_up_max(col, row_index);
	max_down = check_down_max(col, row_index);
	constraint_up = arguments[col_index];
	constraint_down = arguments[col_index + 4];
	printf("max_up: %d - constrain%d\nmax_down:%d - constrain%d\n", max_up, constraint_up, max_down, constraint_down);
	if (check_repetition(col))
	{
		return (1);
	}
	if (max_up > constraint_up || max_down > constraint_down)
	{
		return (1);
	}
	return (0);
}
