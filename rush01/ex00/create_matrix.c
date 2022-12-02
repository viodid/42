/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:46:37 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/13 22:15:33 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_memory(int **matrix, int row);
int		**initialize_matrix(int **matrix, int size);

int	**create_matrix(int size)
{
	int	**matrix;
	int i;
	int j;

	matrix = malloc(size * sizeof(int *));
	if (matrix == NULL)
	{
		return 0;
	}
	i = 0;
	while (i < size)
	{
		matrix[i] = malloc(size * sizeof(int));
		if (matrix[i] == NULL)
		{
			free_memory(matrix, i);
			return 0;
		}
		i++;
	}
	return (initialize_matrix(matrix, size));
}

int	**initialize_matrix(int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			matrix[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (matrix);
}

void free_memory(int **matrix, int row)
{
	int i;

	i = 0;
	while (i < row)
	{
		free(matrix[i]);
		i++;
	}
}