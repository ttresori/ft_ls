# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmand <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 21:43:02 by carmand           #+#    #+#              #
#    Updated: 2017/10/23 19:51:06 by ttresori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =	main.c \
		ls_option.c \
		ls_sort.c \
		ls_print.c \
		ls_print_error.c \
		free_ls.c  \
		ft_stat.c \
		ft_right.c \
		open_dir.c \
		check_new_dir.c \
		ls_sort_t.c \
		l_info.c	\
		ft_padding.c \
		link_print.c \
		ft_size.c \
		print_file.c \
		sort_dir.c \
		sort_dir_t.c \
		sort_error.c \
		#help_ls_option.c

TMP = $(SRC:.c=.o)

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(LIB) $(SRC)
	$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft
	$(CC) $(FLAGS) $(TMP) -o $(NAME)  -L ./libft -lft -I . -I ./libft/

$(LIB):
	make -C libft

clean:
	rm -f $(TMP)
	make -C libft clean

noflags: $(LIB) $(SRC)
	$(CC) -c $(SRC) -I . -I ./libft
	$(CC) $(TMP) -o $(NAME)  -L ./libft -lft -I . -I ./libft/


fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all
