/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:24:39 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/23 18:34:46 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	map_columns(char *str)
{
	int	i;
	int	columns;

	i = 5;
	columns = 0;
	while (str[i] != '\n')
	{
		i++;
		columns++;
	}
	return (columns);
}

char	*parser_info_map(char *str)
{
	int		i;
	char	*info_mapa;
	info_mapa = malloc(4 * sizeof(char));
	i = 0;
	while (str[i] != '\n')
	{
		info_mapa[i] = str[i];
		i++;
	}
	return (info_mapa);
}

char	**parser_map(char *str)
{
	int		i;
	int		j;
	int		c;
	char	**map;

	c = 0;
	while (*str)
	{
		if (*str == '\n')
			break ;
		str++;
		c++;
	}
	c++;
	i = 0;
	map = create_char_matrix(get_rows_from_symbols(str), map_columns(str));
	while (i < get_rows_from_symbols(str))
	{
		printf("here\n");
		printf("other here\n");
		j = 0;
		while (j < map_columns(str))
		{
			map[i][j] = str[c];
			c++;
			j++;
		}
		i++;
		c++;
	}
	return (map);
}
