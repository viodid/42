/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_algorithms_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:20:12 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/23 18:22:43 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	*get_rows_cols(char **matrix_char)
{
	int	*rows_cols;

	rows_cols = malloc(sizeof(int) * 2);
	if (!rows_cols)
		return (0);
	rows_cols[0] = matrix_columns(matrix_char);
	rows_cols[1] = matrix_rows(matrix_char);
	return (rows_cols);
}

void	i_c_matrix(int **matrix_int, char **matrix_char, char *file)
{
	char	*charset;
	int		row;
	int		col;
	int		*rows_cols;

	charset = get_marks_from_file(file);
	rows_cols = malloc(sizeof(int) * 2);
	rows_cols = get_rows_cols(matrix_char);
	row = 0;
	while (row < rows_cols[1])
	{
		col = 0;
		while (col < rows_cols[0])
		{
			if (matrix_int[row][col] == 0)
				matrix_char[row][col] = charset[1];
			else if (matrix_int[row][col] == 1)
				matrix_char[row][col] = charset[0];
			else if (matrix_int[row][col] == 2)
				matrix_char[row][col] = charset[2];
			col++;
		}
		row++;
	}
}

int	**duplicate_matrix(int  **map, int rows, int columns)
{
	int	**matrix;
	int	i;
	int	j;

	i = 0;
	matrix = create_int_matrix(rows, columns);
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			matrix[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (matrix);
}
