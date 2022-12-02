/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcolumns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:27 by rsanz-de          #+#    #+#             */
/*   Updated: 2022/11/22 14:10:32 by rsanz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_manual_input(char *manual_input_file)
{
	char	*line;
	int		input_rows;
	int		i;

	i = 0;
	line = malloc (100000 * sizeof(char));
	if (line == NULL)
		return (1);
	read (1, manual_input_file, 10000);
	input_rows = get_rows_from_symbols(manual_input_file);
	while (i < input_rows)
	{
		read (1, line, 99999);
		ft_str_concat (manual_input_file, line);
		i++;
	}
	return (0);
}
