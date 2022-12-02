/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:23:06 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/04 10:19:23 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_putchar(char c);
char	int_to_char(int n);
void ft_putchar_comb(int a, int b, int c, int comma);

int	main(void)
{
	ft_print_comb();
	return (0);
}

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
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 2;

	while (a <= 9)
	{
		b = a + 1;
		while (b <= 9)
		{
			c = b + 1;
			while (c <= 9)
			{
				if (a == 7 && b == 8 && c == 9)
				{
					ft_putchar_comb(a, b, c, 0);
				}
				else
				{
					ft_putchar_comb(a, b, c, 1);
				}
				++c;
			}
			++b;
		}
		++a;
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
