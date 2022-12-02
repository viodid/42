/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:17 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/12 16:45:25 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	handle_arguments(char *argv)
{
	int	counter;

	counter = 0;
	while (*argv)
	{
		if (counter % 2 == 0)
		{
			if (!(*argv >= 49 && *argv <= 52))
			{
				return (1);
			}
		}
		else
		{
			if (*argv != 32)
			{
				return (1);
			}
		}
		counter++;
		argv++;
	}
	if (counter != 31)
	{
		return (1);
	}
	return (0);
}

void	print_error(char *error)
{

	write(1, error, 6);
}