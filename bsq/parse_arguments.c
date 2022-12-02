/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:17:46 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/23 14:47:23 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	parse_argument(char *argument)
{
	char *file;

	file = read_file(argument);
	if (!file)
	{
		return (1);
	}
	if (check_file(file))
	{
		//printf("Error format input file - parse_arguments.c - line 26\n");
		return (1);
	}
	//free(file);
	return (0);
}