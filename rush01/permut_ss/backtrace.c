/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:49:13 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/13 18:16:07 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_number(int **matrix, int row_index, int column_index, int *arguments);

int	**backtrace(int **matrix, int *row_col, int n, int *args)
{
	matrix[row_col[0]][row_col[1]] = n;
	if (!check_number(matrix, row_col[0], row_col[1], args))
	{
		if (n != 1)
			backtrace(matrix, row_col, n - 1, args);
		else
		{
			matrix[row_col[0]][row_col[1]] = 0;
			if ((row_col[1] == 0) && (row_col[0] != 0))
			{
				row_col[1] = 3;
				backtrace(matrix, row_col, matrix [row_col[0] - 1][3] - 1, args);
			}
			else if ((row_col[1] == 0) && (row_col[0] == 0))
			{
				return (0);
			}
			else
			{
				row_col[1] = row_col[1] - 1;
				backtrace(matrix, row_col, matrix[row_col[0]][row_col[1] - 1] - 1, args);
			}
		}
	}
	else
	{
		if ((row_col[1] == 3) && (row_col[0] != 3))
		{
			row_col[0] = row_col[0] + 1;
			row_col[1] = 0;
			backtrace(matrix, row_col, 4, args);
		}
		else if ((row_col[1] == 3) && (row_col[0] == 3))
		{
			return (matrix);
		}
		else
		{
			row_col[1] = row_col[1] + 1;
			backtrace(matrix, row_col, 4, args);
		}
	}
	return (matrix);
}
