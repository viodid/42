/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:20:22 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/23 17:36:03 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "headers.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	print_map(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int	print_map_int(int **map, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			printf("%d ",map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
