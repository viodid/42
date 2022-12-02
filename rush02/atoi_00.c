/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:26:41 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/20 23:13:59 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_num(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ':')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

char	*ft_atoi_pal(char *str)
{
	char	*pal;
	int		j;

	j = 0;
	pal = malloc(50 * sizeof(char));
	while (*str != ':')
		str++;
	str++;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			pal[j] = *str;
			str++;
		}
		else
		{
			pal[j] = ' ';
			while (*str == ' ' || *str == '\t')
				str++;
		}
		j++;
	}
	return (pal);
}
