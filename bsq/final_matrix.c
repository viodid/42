/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:04:18 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/23 17:36:15 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	*coordinates_max(int **number_map)
{
	int	i;
	int	j;
	int	*coordinates_max;

	i = 0;
	coordinates_max = malloc(3 * sizeof(int));
	coordinates_max[2] = 0;
	while (number_map[i])
	{
		j = 0;
		while (number_map[i][j])
		{
			if (number_map[i][j] > coordinates_max[2])
			{
				coordinates_max[0] = i;
				coordinates_max[1] = j;
				coordinates_max[2] = number_map[i][j];
			}
			j++;
		}
		i++;
	}
	return (coordinates_max);
}

int	final_map(int **number_map, int **matrix)
{
	int	i;
	int	j;
	int	max;
	int	*c_max;

	c_max = coordinates_max(number_map);
	i = c_max[0];
	max = c_max[2];
	while (i < (c_max[0] + max))
	{
		j = c_max[1];
		while (j < (c_max[1] + max))
		{
			matrix[i][j] = 2;
			j++;
		}
		i++;
	}
	return (0);
}
