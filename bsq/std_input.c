/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:48:17 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/23 17:06:43 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*std_input(void)
{
	char	c;
	char	before_c;
	char	*buffer;
	char	*start_buffer;


	before_c = 0;
	buffer = malloc(sizeof(char) * 1000000);
	if (!buffer)
		return (0);
	//int fl1 = open(&c, O_WRONLY);
	start_buffer = buffer;
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == '\n' && before_c == '\n')
			break;
		*buffer = c;
		buffer++;
		before_c = c;
	}
	return (start_buffer);
}
