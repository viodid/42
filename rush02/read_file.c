/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:35:33 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/20 23:35:24 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "struct.h"

t_node	*file_parser(char *buffer, t_node *header);
void	print_str(char *str);

t_node	*read_file(char *file, t_node *header)
{
	char	*buffer;
	char	*start_buffer;
	int		file_desciptor;
	int		file_close;

	buffer = malloc(1000000 * sizeof(char));
	if (buffer == NULL)
		return (0);
	start_buffer = buffer;
	file_desciptor = open(file, O_RDONLY);
	if (file_desciptor == -1)
	{
		return (0);
	}
	if (read(file_desciptor, buffer, 1000000 * sizeof(char)) == -1)
		return (0);
	file_close = close(file_desciptor);
	if (file_close == -1)
		return (0);
	return (file_parser(start_buffer, header));
}
