SRCS	= main.c read_file.c parse_arguments.c columns_check.c check_file.c helpers.c check_file_helpers.c std_input.c create_matrix.c final_matrix.c matrix_algorithms_functions.c matrix_algorithms_helpers.c matrix.c parser.c print_matrix.c solve_matrix.c

NAME	= bsq

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.phony: clean fclean re
