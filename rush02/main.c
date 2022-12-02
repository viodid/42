/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:47:35 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/21 21:32:05 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

t_node	*read_file(char *file, t_node *header);
int		parse_arguments(int argc, char *argv[]);
void	print_str(char *str);
int		print_number(int n, t_node *header);
void	print_str(char *str);
int		str_to_int(char *str);

int	main(int argc, char *argv[])
{
	t_node	*header;

	header = NULL;
	if (parse_arguments(argc, argv))
	{
		print_str("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		header = read_file("numbers.dict.txt", header);
		print_number(str_to_int(argv[1]), header);
	}
	else if (argc == 3)
	{
		header = read_file(argv[1], header);
		if (header == NULL)
		{
			print_str("Dict Error\n");
			return (1);
		}
		print_number(str_to_int(argv[2]), header);
	}
	print_str("\n");
	return (0);
}
