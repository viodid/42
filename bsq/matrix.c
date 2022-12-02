/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:51:24 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/23 17:38:22 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	matrix_columns(char	**matrix)
{
	int	columns;

	columns = 0;
	while (matrix[0][columns])
		columns++;
	return (columns);
}

int	matrix_rows(char **matrix)
{
	int	rows;

	rows = 0;
	while (matrix[rows])
		rows++;
	return (rows);
}

int	**number_matrix(char **map, char *info_map)
{
	int	**matrix;
	int	i;
	int	j;
	int	rows;
	int	columns;

	rows = matrix_rows(map);
	columns = matrix_columns(map);
	matrix = create_int_matrix(rows, columns);
	i = 0;
	
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (map[i][j] == info_map[1])
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}
