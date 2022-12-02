/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:33:47 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/15 13:02:13 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

int	*parse_arguments(char *numbers, int size);
int	*create_numbers(int size);
int check_repetition( int *column);

int	check_left_max(int *row, int row_index)
{
	int	i;
	int	visibles_from_left;
	int	max_block;

	i = 0;
	max_block = row[i];
	if (max_block != 0)
	{
		visibles_from_left = 1;
	}
	else
	{
		visibles_from_left = 0;
	}
	while (i <= row_index)
	{
		if (row[i] > max_block)
		{
			visibles_from_left++;
			max_block = row[i];
		}
		i++;
	}

	return (visibles_from_left);
}

int check_right_max(int *row, int row_index)
{
	int	i;
	int	visibles_from_right;
	int	max_block;

	i = 3;
	max_block = row[i];
	if (max_block != 0)
	{
		visibles_from_right = 1;
	}
	else
	{
		visibles_from_right = 0;
	}
	while (i >= row_index)
	{
		if (row[i] > max_block)
		{
			visibles_from_right++;
			max_block = row[i];
		}
		i--;
	}

	return (visibles_from_right);
}

int	check_up_max(int *column, int row_index)
{
	int	i;
	int	visibles_from_up;
	int	max_block;

	i = 0;
	max_block = column[i];
	if (max_block != 0)
	{
		visibles_from_up = 1;
	}
	else
	{
		visibles_from_up = 0;
	}
	while (i <= row_index)
	{
		if (column[i] > max_block)
		{
			visibles_from_up++;
			max_block = column[i];
		}
		i++;
	}

	return (visibles_from_up);
}

int	check_down_max(int *column, int column_index)
{
	int	i;
	int	visibles_from_down;
	int	max_block;

	i = 3;
	max_block = column[i];
	if (max_block != 0)
	{
		visibles_from_down = 1;
	}
	else
	{
		visibles_from_down = 0;
	}
	while (i >= column_index)
	{
		if (column[i] > max_block)
		{
			visibles_from_down++;
			max_block = column[i];
		}
		i--;
	}

	return (visibles_from_down);
}

int	check_constraints_row(int *row, int row_index, int col_index, int *arguments)
{
	int	max_left;
	int max_right;
	int	constraint_left;
	int	constraint_right;

	max_left = check_left_max(row, col_index);
	max_right = check_right_max(row, col_index);
	constraint_left = arguments[row_index + 8];
	constraint_right = arguments[row_index + 12];
/* 	if(row_index ==3)
		printf("max_left: %d - const left %d\n max_rigt %d - constr right %d\n", max_left, constraint_left, max_right, constraint_right); */
	if (check_repetition(row))
	{
		return (1);
	}
/* 	if (row_index == 3)
	{
		if (max_left != constraint_left || max_right != constraint_right)
		{
			return (1);
		}
	}
	else if (max_left > constraint_left || max_right > constraint_right)
	{
		return (1);
	} */

	if (max_left > constraint_left || max_right > constraint_right)
	{
		return (1);
	}

	return (0);
}

int	check_constraints_col(int *col, int row_index, int col_index, int *arguments)
{
	int	max_up;
	int max_down;
	int	constraint_up;
	int	constraint_down;

	max_up = check_up_max(col, row_index);
	max_down = check_down_max(col, row_index);
	constraint_up = arguments[col_index];
	constraint_down = arguments[col_index + 4];
	//printf("max_up: %d - constrain%d\nmax_down:%d - constrain%d\n", max_up, constraint_up, max_down, constraint_down);
/* 	if(row_index ==3)
		printf("max_up: %d - constrain%d\nmax_down:%d - constrain%d\n", max_up, constraint_up, max_down, constraint_down); */
	if (check_repetition(col))
	{
		return (1);
	}
/* 	if (max_up > constraint_up || max_down > constraint_down)
	{
		return (1);
	} */

	if (row_index == 3 && col_index==0)
	{
		if ((max_up) != constraint_up || (max_down) != constraint_down)
		{
			return (1);
		}
	}
	else if(row_index == 3 && col_index>0)
		{
			if ((max_up +1) == constraint_up || (max_down+1) == constraint_down)
				return (0);
		}
	else if (max_up > constraint_up || max_down > constraint_down)
		{
			return (1);
		}
	return (0);
}
