/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:00:39 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/22 18:24:49 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	map_generator(int x, int y, int density, int file_descriptor)
{
	int	i;
	int	j;

	write(file_descriptor, &y, sizeof(int));
	write(file_descriptor, ".ox", 3);
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if ((y / 2) < density)
			{
				write(file_descriptor, "o", 1);
			}
			else
			{
				write(file_descriptor, ".", 1);
			}
			j++;
		}
		i++;
	}
	write(file_descriptor, "\n", 1);
}
