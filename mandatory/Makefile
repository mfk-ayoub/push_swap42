# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 23:35:46 by ayel-mou          #+#    #+#              #
#    Updated: 2024/01/29 03:30:08 by ayel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE = ./mandatory/push_swap.h

FLAGS = 
CC = cc

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN 	= \033[1;36m

CFILES = main.c \
		 sort_algo.c\
		 check_sorted.c\
		 free_stack.c 


CHELPER = ../utlis/check_min_max.c\
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
		  ../utlis/ft_strdup.c\
		  ../utlis/ft_memcpy.c \
		  ../operations/rotate.c \
		  ../operations/swap.c \


OBJ = $(CFILES:.c=.o) $(CHELPER:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(RED)making.$(YELLOW)\n"
	@sleep 0.2
	@printf "$(RED)making..$(YELLOW)\n"
	@sleep 0.2
	@printf "$(RED)making...$(YELLOW)\n"
	@sleep 0.2
	@printf "$(RED)making...$(YELLOW)\n"
	@sleep 0.2
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@printf "$(GREEN)successfully !$(GREEN)\n"
	

%.o: %.c $(INCLUDE)
	@$(CC) $(FLAGS) -c $< -o $@
	

clean:
	@printf "$(RED)Cleaning.$(YELLOW)\n"
	@sleep 0.2
	@printf "$(RED)Cleaning..$(YELLOW)\n"
	@sleep 0.2
	@printf "$(RED)Cleaning...$(YELLOW)\n"
	@sleep 0.2
	@printf "$(RED)Cleaning....$(YELLOW)\n"
	@sleep 0.2
	@rm -rf $(OBJ)
	@printf "\n"
	@clear
	@printf "$(GREEN)Cleaned successfully !$(GREEN)\n"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
