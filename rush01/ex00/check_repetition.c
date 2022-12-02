/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repetition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:08:10 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/13 23:08:36 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int check_repetition( int *column)
{
	int key;
	int j;
	int counter = 0;
	int size = 4;
	int aux_arr[size];

	while (counter < size)
	{
		aux_arr[counter] = column[counter];
		counter++;
	}
	counter = 0;

	while (counter < size)
	{
		key = *(aux_arr + counter);
		j = counter - 1;
		while (j >= 0 && *(aux_arr + j) > key)
		{
			*(aux_arr + j + 1) = *(aux_arr + j);
			j--;
		}
		*(aux_arr + j + 1) = key;
		counter++;
	}
	counter = 1;
	while(counter < size)
	{
		if((aux_arr[counter] != 0) && aux_arr[counter-1] == aux_arr[counter])
			return(1);
		counter ++;
	}
	return (0);
}