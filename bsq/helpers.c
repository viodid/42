/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:32:02 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/24 12:30:08 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_atoi_special(char *str)
{
	int	output;
	int	length;
	int	i;

	output = 0;
	i = 0;
	length = str_len(str);
	while (i < length - 3)
	{
		output *= 10;
		output += *str - 48;
		str++;
		i++;
	}
	return (output);
}

int	is_numeric(char c)
{
	if (c < '0' || c > '9')
	{
		return (1);
	}
	return (0);
}

void	str_print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*get_marks_from_file(char *file)
{
	char	*marks;
	char	*start_marks;

	marks = malloc(sizeof(char) * 4);
	start_marks = marks;
	while (*file)
	{
		if (*file == '\n')
		{
			while (*marks)
			{
				*marks = *(file - 3);
				marks++;
				file++;
			}
			return (start_marks);
		}
		file++;
	}
	printf("marks check: %s\n", start_marks);
	return (0);
}