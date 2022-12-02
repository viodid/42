/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:01 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/23 17:46:00 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	check_file(char *file)
{
	if (check_columns(file))
	{
		printf("Columns are misaligned\n");
		return (1);
	}
	if (check_symbols(file))
	{
		return (1);
	}
	return (0);
}

int	check_symbols(char *file)
{
	char	*first_line;
	char	*start_first_line;
	char	*start_file;

	start_file = file;
	first_line = malloc(sizeof(char) * 15);
	start_first_line = first_line;
	while (*file)
	{
		if (*file == '\n')
		{
			*first_line = '\0';
			break ;
		}
		*first_line = *file;
		file++;
		first_line++;
	}
	if (check_symbols_helper(start_first_line, start_file))
	{
		free(start_first_line);
		return (1);
	}
	free(start_first_line);
	return (0);
}

int	check_symbols_helper(char *symbols, char *file)
{
	int	rows;

	if (str_len(symbols) < 4)
	{
		printf("Incomplete symbols in header\n");
		return (1);
	}
	if (*symbols < '0' || *symbols > '9' || *symbols == '-')
	{
		printf("Header not a number\n");
		return (1);
	}
	rows = get_rows_from_symbols(symbols);
	if (rows == -1)
	{
		printf("Rows header and matrix don't match or header is larger than needed\n");
		return (1);
	}
	if (rows != (count_rows(file) - 1))
	{
		printf("Rows does not match with matrix or header is larger than needed\n");
		return (1);
	}
	symbols++;
	if (compare_symbols(get_symbols_marks_header(symbols), get_matrix(file)))
	{
		return (1);
	}
	return (0);
}

int	compare_symbols(char *marks, char *matrix)
{
	while (*matrix)
	{
		if (*matrix != marks[0] && *matrix != marks[1] && *matrix != '\n')
		{
			printf("Error symbols header: %s and matrix: %c symblols don't match - check_file.c - line 97\n", marks, *matrix);
			return (1);
		}
		matrix++;
	}
	return (0);
}
