# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 23:35:46 by ayel-mou          #+#    #+#              #
#    Updated: 2024/01/25 06:17:16 by ayel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
INCLUDE = ./mandatory/push_swap.h

FLAGS = -Wall -Wextra -Werror
CC = cc -g
CFILES = main.c \
         sort_algo.c

CHELPER = ../utlis/check_min_max.c \
          ../utlis/ft_check_errors.c \
          ../utlis/ft_putstr_fd.c \
          ../utlis/initstack.c \
          ../utlis/ft_atoi.c \
          ../utlis/ft_isdigit.c \
          ../utlis/ft_split.c \
          ../utlis/stack_size.c \
		  ../utlis/string_to_av.c

OBJ = $(CFILES:.c=.o)
OBJH = $(CHELPER:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ) $(OBJH)
	$(CC) $(FLAGS) $(OBJ) $(OBJH) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
