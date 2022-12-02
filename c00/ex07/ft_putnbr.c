/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:35:13 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/06 18:29:22 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
int		count_length_check_positive(int number, int func);
int		get_module(int c);
void	print_output(char c, int nb, int counter);

void	ft_putnbr(int nb)
{
	int		number;
	int		counter;
	int		c;
	int		module;
	char	output_char;

	number = count_length_check_positive(nb, 1);
	counter = count_length_check_positive(number, 0);
	c = 0;
	module = get_module(counter);
	while (c < counter)
	{
		output_char = (number / module) + 48;
		number = number - (module * (number / module));
		module = module / 10;
		print_output(output_char, nb, c);
		++c;
	}
	write(1, &counter, 1);
}

int	get_module(int c)
{
	int	output;
	int	counter;

	output = 1;
	counter = 0;
	while (counter < c - 1)
	{
		output = output * 10;
		++counter;
	}
	return (output);
}

int	count_length_check_positive(int number, int func)
{
	int	b;
	int	count;

	if (func == 0)
	{
		count = 0;
		while (number > 0)
		{
			count++;
			number /= 10;
		}
		return (count);
	}
	if (number < 0)
	{
		b = number * 2;
		number = number - b;
	}
	return (number);
}

void	print_output(char c, int nb, int counter)
{
	if (nb >= 0)
	{
		write(1, &c, 1);
	}
	else
	{
		if (counter == 0)
		{
			write(1, "-", 1);
		}
		write(1, &c, 1);
	}
}
