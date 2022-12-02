/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:57:44 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/20 23:04:35 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

int		ft_atoi_num(char *str);
char	*ft_atoi_pal(char *str);
t_node	*create_linked_list(int num, char *str, t_node *header);
int		str_len(char *str);

t_node	*file_parser(char *buffer, t_node *header)
{
	char	*line_to_parse;
	char	*start_line_to_parse;

	line_to_parse = malloc(100 * sizeof(char));
	if (line_to_parse == NULL)
	{
		return (0);
	}
	start_line_to_parse = line_to_parse;
	while (*buffer)
	{
		if (*buffer == '\n')
		{
			*(line_to_parse++) = '\0';
			if (str_len(start_line_to_parse) > 1)
				header = create_linked_list(ft_atoi_num(start_line_to_parse),
						ft_atoi_pal(start_line_to_parse), header);
			line_to_parse = start_line_to_parse;
		}
		else
			*line_to_parse = *buffer;
		buffer++;
		line_to_parse++;
	}
	return (header);
}

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
