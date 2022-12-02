/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:23:06 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/06 16:58:57 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_putchar(char c);
char	int_to_char(int n);
void	ft_putchar_comb(int a, int b, int c, int comma);

void	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
}

char	int_to_char(int n)
{
	char	c;

	c = n + '0';
	return (c);
}

void	ft_print_comb(void)
{
	int	int_arr[3];

	int_arr[0] = 0;
	while (int_arr[0] <= 9)
	{
		int_arr[1] = int_arr[0] + 1;
		while (int_arr[1] <= 9)
		{
			int_arr[2] = int_arr[1] + 1;
			while (int_arr[2] <= 9)
			{
				if (int_arr[0] == 7 && int_arr[1] == 8 && int_arr[2] == 9)
				{
					ft_putchar_comb(int_arr[0], int_arr[1], int_arr[2], 0);
				}
				else
				{
					ft_putchar_comb(int_arr[0], int_arr[1], int_arr[2], 1);
				}
				++int_arr[2];
			}
			++int_arr[1];
		}
		++int_arr[0];
	}
}

void	ft_putchar_comb(int a, int b, int c, int comma)
{
	if (comma == 1)
	{
		ft_putchar(int_to_char(a));
		ft_putchar(int_to_char(b));
		ft_putchar(int_to_char(c));
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
	{
		ft_putchar(int_to_char(a));
		ft_putchar(int_to_char(b));
		ft_putchar(int_to_char(c));
	}
}
