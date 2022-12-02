/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nuber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:33:03 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/03 16:47:27 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_number(void);
char	int_to_char(int n);

int	main(void)
{
	ft_print_number();
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
}

void	ft_print_number(void)
{
	int	n;

	n = 0;
	while (n <= 9)
	{
		ft_putchar(int_to_char(n));
		++n;
	}
}

char	int_to_char(int n)
{
	char	c;

	c = n + '0';
	return (c);
}
