/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:25:57 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/23 14:40:12 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*get_symbols_marks_header(char *header)
{
	char	*marks;
	char	*start_marks;
	char	i;

	marks = malloc(sizeof(char) * 3);
	if (!marks)
		return (0);
	start_marks = marks;
	header += (str_len(header) - 3);
	i = 0;
	while (i < 2)
	{
		*marks = *header;
		marks++;
		header++;
		i++;
	}
	return (start_marks);
}

char	*get_matrix(char *file)
{
	while (*file != '\n')
		file++;
	return (++file);
}

int	get_rows_from_symbols(char *str)
{
	int		output;
	int		length;
	int		i;

	output = 0;
	i = 0;
	length = str_len(str);
	while (i < (length - 3))
	{
		if (is_numeric(str[i]))
			return (-1);
		output *= 10;
		output += str[i] - 48;
		i++;
	}
	return (output);
}
