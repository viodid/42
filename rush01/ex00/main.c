/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:55:10 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/15 12:50:37 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		handle_arguments(char *argv);
void	print_error(char *error);
int		**create_matrix(int size);
int		*parse_arguments(char *numbers, int size);
int		check_number(int **matrix, int row_index, int column_index, int *arguments);
int		check_number_final_check(int **matrix, int row_index, int column_index, int *arguments);
int	**backtrace(int **matrix, int row, int col, int n, int *args);

#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2 || handle_arguments(argv[1]))
	{
		print_error("Error\n");
		return (1);
	}
	
	int *arg = parse_arguments(argv[1], 4);
	/*
	int	i = 0;
	while (i < 16)
	{
		printf("%d", arg[i]);
		i++;
	}
	printf("\n");
	*/

	int **matrix = create_matrix(4);
	matrix = backtrace(matrix, 0, 0, 4, arg);
	
	int i = 0;
	int j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
/* 	check_number_final_check(matrix, 0, 3, arg);
	printf("\n \n");
	check_number_final_check(matrix, 1, 3, arg);
	printf("\n \n");
	check_number_final_check(matrix, 2, 3, arg);
	printf("\n \n");
	check_number_final_check(matrix, 3, 3, arg); */
	
	return (0);
}
