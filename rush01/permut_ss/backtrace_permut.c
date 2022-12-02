/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrace_permut.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:49:13 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/13 23:18:17 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_number_permut(int **matrix, int row_index, int *arguments);

int	**backtrace_permut(int **matrix, int row, int i, int *args, int **permutations)
{

	matrix[row]= permutations[i];
	if (!check_number_permut(matrix, row, args))
	{
		if (i != 0)
			backtrace_permut(matrix, row, i - 1, args, permutations);
		else
		{
			matrix[row] = permutations[24];
			if (row == 0)
			{
				return 0;
			}
			else
			{
				backtrace_permut(matrix, row, i - 1, matrix[row - 1], args);
			}
		}
	}
	else
	{
		if (row != 3)
		{
			backtrace_permut(matrix, row + 1, 23, args, permutations);
		}
		else if (row == 3)
		{
			return matrix;
		}
	}
	return matrix;
}