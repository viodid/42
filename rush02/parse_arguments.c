/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:39:08 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/20 23:24:41 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_str(char *str);

int	char_to_int(char *str)
{
	int	output;

	output = 0;
	while (*str)
	{
		if (!(*str >= 0) && !(*str <= 9))
		{
			return (-1);
		}
		output *= 10;
		output += *str + 48;
		str++;
	}
	return (output);
}

int	parse_check(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	parse_arguments(int argc, char *argv[])
{
	char	*str;

	if (argc > 3 || argc == 1)
	{
		return (1);
	}
	else if (argc == 2)
	{
		str = argv[1];
		if (char_to_int(argv[1]) < 0 || parse_check(str))
		{
			return (1);
		}
	}
	else if (argc == 3)
	{
		str = argv[2];
		if (char_to_int(argv[2]) < 0 || parse_check(str))
		{
			return (1);
		}
	}
	return (0);
}
