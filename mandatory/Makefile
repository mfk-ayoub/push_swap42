# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 23:35:46 by ayel-mou          #+#    #+#              #
#    Updated: 2024/02/03 16:46:51 by ayel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE = ./mandatory/push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = cc

CFILES = main.c \
		 sort_algo.c \
		 check_sorted.c \
		 free_stack.c \
		 big_sort.c \

CHELPER = ../utlis/check_min_max.c \
		  ../utlis/ft_check_errors.c \
		  ../utlis/ft_putstr_fd.c \
		  ../utlis/initstack.c \
		  ../utlis/ft_atoi.c \
		  ../utlis/ft_isdigit.c \
		  ../utlis/ft_split.c \
		  ../utlis/stack_size.c \
		  ../utlis/ft_strlen.c \
		  ../utlis/ft_strlcat.c \
		  ../utlis/ft_strjoin.c \
		  ../utlis/ft_putendl_fd.c \
		  ../utlis/ft_strdup.c \
		  ../utlis/ft_memcpy.c \
		  ../operations/rotate.c \
		  ../operations/swap.c \
		  ../operations/push.c \
		  ../operations/reverse_rotate.c

OBJ = $(CFILES:.c=.o) $(CHELPER:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)


%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
