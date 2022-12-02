# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifortuny <ifortuny@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 17:56:09 by ifortuny          #+#    #+#              #
#    Updated: 2022/11/20 23:17:53 by dyunta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02

OBJS	= main.o file_parser.o node_list.o read_file.o atoi_00.o nodes.o parse_arguments.o helpers.o

CFLAGS	= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

main.o : main.c
file_parser.o : file_parser.c
node_list.o : node_list.c
read_file.o : read_file.c
atoi_00.o : atoi_00.c
nodes.o : nodes.c
parse_arguments.o : parse_arguments.c
helpers.o : helpers.c

.phony: clean
clean:
	rm -f *.o 

.phony: fclean
fclean: 
	rm $(NAME)
