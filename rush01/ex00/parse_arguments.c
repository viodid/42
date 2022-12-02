/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:03:27 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/13 21:54:01 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*parse_arguments(char *numbers, int size)
{
	int	*arguments;
	int	*start_arguments;

	arguments = malloc(sizeof(int) * size * size);
	if (arguments == NULL)
	{
		free(arguments);
		return (0);
	}
	start_arguments = arguments;
	/* Iterate through numbers. Converting them from char to int */
	while (*numbers)
	{
		if (*numbers >= '1' && *numbers <= '4')
		{
			*arguments = (*numbers - 48);
			arguments++;
		}
		numbers++;
	}
	return (start_arguments);
}
