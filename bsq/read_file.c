/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:25:29 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/22 17:02:13 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*read_file(char *file)
{
	char	*large_buffer;
	char	*start_large_buffer;
	int		file_descriptor;
	int		length_file;

	file_descriptor = open(file, O_RDONLY);
	if (file_descriptor == -1)
	{
		printf("Error open file - read_file.c - line 25\n");
		return (0);
	}
	large_buffer = malloc(sizeof(char) * 1000000);
	if (!large_buffer)
	{
		printf("Error buffer allocate - read_file.c - line 31\n");
		return (0);
	}
	start_large_buffer = large_buffer;
	length_file = read(file_descriptor, large_buffer, 1000000 * sizeof(char));
	if (length_file == -1)
	{
		printf("Error reading file - read_file.c - line 38");
		return (0);
	}
	if (close(file_descriptor == -1))
	{
		printf("Error closing file - read_file.c - line 43\n");
		return (0);
	}
	return (get_exact_buffer((start_large_buffer), length_file));
}

char	*get_exact_buffer(char *large_buffer, int length_file)
{
	char	*exact_buffer;
	char	*start_exact_buffer;
	char	*start_large_buffer;

	start_large_buffer = large_buffer;
	exact_buffer = malloc(sizeof(char) * length_file + 1);
	if (!exact_buffer)
	{
		printf("Error exact_buffer allocate - read_file.c - line 57\n");
		return (0);
	}
	start_exact_buffer = exact_buffer;
	while (length_file)
	{
		*exact_buffer = *large_buffer;
		exact_buffer++;
		large_buffer++;
		length_file--;
	}
	*exact_buffer = '\0';
	free(start_large_buffer);
	return (start_exact_buffer);
}
