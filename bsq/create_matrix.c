/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:13:52 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/23 18:38:36 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	free_memory_int(int **matrix, int column)
{
	int	i;

	i = 0;
	while (i < column)
	{
		free(matrix[i]);
		i++;
	}
}

int	**create_int_matrix(int rows, int columns)
{
	int	**matrix;
	int	i;

	matrix = malloc(rows * sizeof(int *));
	if (matrix == NULL)
		return (0);
	i = 0;
	while (i < rows)
	{
		matrix[i] = malloc(columns * sizeof(int));
		if (matrix[i] == NULL)
		{
			free_memory_int(matrix, i);
			return (0);
		}
		i++;
	}
	return (matrix);
}

void	free_memory(char **matrix, int column)
{
	int	i;

	i = 0;
	while (i < column)
	{
		free(matrix[i]);
		i++;
	}
}

char	**create_char_matrix(int rows, int columns)
{
	char	**matrix;
	int		i;

	matrix = malloc(rows * sizeof(char *));
	if (matrix == NULL)
		return (0);
	i = 0;
	while (i < rows)
	{
		matrix[i] = malloc(columns * sizeof(char));
		if (matrix[i] == NULL)
		{
			free_memory(matrix, i);
			return (0);
		}
		i++;
	}
	return (matrix);
}
