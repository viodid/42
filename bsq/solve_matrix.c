/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:14:16 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/23 17:36:08 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	min_rightdown(int **matrix, int row, int col)
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

int	solve_matrix(int **matrix, int rows, int columns)
{
    int aux;

	rows = rows - 2;
	while (rows >= 0)
	{
		aux = columns - 2;
		while (aux >= 0)
		{
			if (matrix[rows][aux] == 1)
				matrix[rows][aux] = min_rightdown(matrix, rows, aux) + 1;
			aux--;
		}
		rows--;
	}
	return (0);
}
