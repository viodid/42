
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

	c = n + 48;
	return (c);
}

void	ft_print_comb(void)
{
    int digits[3];

	digits[0] = 0;
	digits[1] = 1;

	while (digits[0] <= 9)
	{
		digits[1] = digits[0] + 1;
		while (digits[1] <= 9)
		{
			digits[2] = digits[1] + 1;
			while (digits[2] <= 9)
			{
				if (digits[0] == 7 && digits[1] == 8 && digits[2] == 9)
				{
					ft_putchar_comb(digits[0], digits[1], digits[2], 0);
				}
				else
				{
					ft_putchar_comb(digits[0], digits[1], digits[2], 1);
				}
				digits[2] = digits[2] + 1;
			}
			digits[1] = digits[1] + 1;
		}
		digits[0] = digits[0] + 1;
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
