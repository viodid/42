/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:47:52 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/23 17:46:14 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	count_rows(char *str)
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

int	check_columns(char *str)
{
	int	*counter_columns;
	int	counter_rows;
	int	i;

	i = 0;
	counter_rows = count_rows (str);
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
