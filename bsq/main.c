/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:39:35 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/24 12:29:58 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	*file;
	char	*argument;

	if (argc == 1)
	{
		file = std_input();
		if (check_file(file))
		{
			str_print("map error\n");
			return (1);
		}
		print_aggregate_matrix(file);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		argument = argv[i];
		if (parse_argument(argument))
		{
			str_print("map error\n");
		}
		else
		{
			print_aggregate_matrix(argument);
		}
		i++;
	}
	printf("Ok!\n");
	return (0);
}
