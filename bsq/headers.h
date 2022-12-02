/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:40:09 by dyunta            #+#    #+#             */
/*   Updated: 2022/11/24 12:30:21 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include <stdio.h>

char	*get_exact_buffer(char *large_buffer, int length_file);
char	*read_file(char *file);
int		parse_argument(char *argument);
int		check_file(char *file);
int		count_rows(char *str);
int		str_len(char *str);
int		check_file(char *file);
int		check_symbols(char *file);
int		check_symbols_helper(char *symbols, char *file);
int		compare_symbols(char *symbols_header, char *symbols_matrix);
int		check_columns(char *str);
int		get_rows_from_symbols(char *str);
int		ft_atoi_special(char *str);
int		is_numeric(char c);
char	*get_symbols_marks_header(char *header);
char	*get_matrix(char *file);
char	*std_input();
void	str_print(char *str);
void	free_memory_int(int **matrix, int column);
int		**create_int_matrix(int rows, int columns);
void	free_memory(char **matrix, int column);
char	**create_char_matrix(int rows, int columns);
int		*coordinates_max(int **number_map);
int		final_map(int **number_map, int **matrix);
void	i_c_matrix(int **matrix_int, char **matrix_char, char *file);
int		**duplicate_matrix(int **map, int rows, int columns);
int		matrix_columns(char	**matrix);
int		**number_matrix(char **map, char *info_map);
int		map_columns(char *str);
char	*parser_info_map(char *str);
char	**parser_map(char *str);
void	ft_putchar(char c);
int		print_map_int(int **map, int rows, int columns);
int		min_rightdown(int **matrix, int row, int col);
int		solve_matrix(int **matrix, int rows, int columns);
int		matrix_rows(char **matrix);
char	*get_marks_from_file(char *file);
void	print_aggregate_matrix(char *file);
#endif