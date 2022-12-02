/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_algorithms_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:19:47 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/23 18:31:11 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	print_aggregate_matrix(char *file)
{
	int	columns;
	int	rows;
	char	**map;
	int		**map_n;
	int		**map_x;
	
	map = parser_map(file);
	printf("here\n");
	columns = matrix_columns(map);
	rows = matrix_rows(map);
	map_n = number_matrix(map, parser_info_map(file));
	map_x = duplicate_matrix(map_n, rows, columns);
	solve_matrix(map_n, rows, columns);
	final_map(map_n, map_x);
	//print_map_int(map_x, rows, columns);
	i_c_matrix(map_x, map, file);
}
