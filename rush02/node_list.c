/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:08:19 by jgarcia2          #+#    #+#             */
/*   Updated: 2022/11/21 22:03:09 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

#include <stdio.h>

t_node	*create_node(int num, char *w, t_node *header);
int		g_space = 0;

int	ft_pow(int base, int exp)
{
	int	sol;

	sol = base;
	while (exp > 1)
	{
		sol = sol * base;
		exp--;
	}
	return (sol);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 1;
	if (g_space == 1)
		write(1, " ", 1);
	g_space = 1;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ncif(int number)
{
	int	n;

	n = 0;
	while (number > 0)
	{
		number = number / 10;
		n++;
	}
	return (n);
}

char	*get_word(int n, t_node *header)
{
	t_node	*pnt;

	pnt = header;
	while (pnt != NULL)
	{
		if (pnt->number == n)
			return (pnt->word);
		pnt = pnt->next;
	}
	return (NULL);
}

int	print_number(int n, t_node *header)
{
	int	x;

	if (n >= 0 && n <= 20)
	{
		ft_putstr(get_word(n, header));
	}
	else if (ncif(n) == 2)
	{
		ft_putstr(get_word(n - n % 10, header));
		ft_putstr(get_word(n % 10, header));
	}
	else if (ncif(n) >= 3)
	{
		if (ncif(n) == 3)
			x = 2;
		else if (ncif(n) % 3 == 0)
			x = ncif(n) - 3;
		else
			x = ncif(n) - (ncif(n) % 3);
		print_number(n / ft_pow(10, x), header);
		ft_putstr(get_word((ft_pow(10, x)), header));
		print_number(n % (ft_pow(10, x)), header);
	}
	return (0);
}
