/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcolumns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:27 by rsanz-de          #+#    #+#             */
/*   Updated: 2022/11/22 14:10:32 by rsanz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_count_rows(char *str)
{
	int	i;
	int	counter_rows;

	i = 0;
	counter_rows = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			counter_rows ++;
		i++;
	}
	if (i > 1 && str[i - 1] != '\n')
		counter_rows ++;
	return (counter_rows);
}

int	ft_rowlenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	ft_check2col(int *counter_columns, int counter_rows)
{
	int	i;

	if (counter_columns [1] == 0)
		return (1);
	i = 2;
	while (i < counter_rows)
	{
		if (counter_columns [i] != counter_columns [i - 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkcolumns(char *str)
{
	int	*counter_columns;
	int	counter_rows;
	int	i;

	i = 0;
	counter_rows = ft_count_rows (str);
	if (counter_rows <= 1)
		return (1);
	if (counter_rows == 2)
		return (0);
	counter_columns = malloc ((counter_rows + 1) * sizeof (int));
	if (counter_columns == NULL)
		return (1);
	while (i < counter_rows)
	{
		counter_columns[i] = ft_rowlenght(str);
		str = str + counter_columns[i] + 1;
		i++;
	}
	if (ft_check2col(counter_columns, counter_rows) == 1)
		return (1);
	free (counter_columns);
	return (0);
}

/* int main (void)
{
	//char text[]="This\nabcdef\nabcdef\nabcdef\nabcdef\n";
	//char text[]="2554\n10\n\n20";
	//char text[]="ab44\ndef\nghi\njkl\n1234";
	//char text[]="ab44\ndef\ndef\n";
	//char text[]="a\n1";
	char *file;

	file = read_file("test1.txt");
	printf("%d \n", ft_checkcolumns(file));

	//printf("%d \n", ft_checkcolumns(text));
	//printf("%d \n", ft_checkcolumns(text));
	//printf("%d \n", ft_count_rows(text));
	return(0);
} */