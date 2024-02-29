# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 23:35:46 by ayel-mou          #+#    #+#              #
#    Updated: 2024/02/29 04:07:23 by ayel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS= checker
INCLUDE = ./mandatory/push_swap.h \
		  ./checker_bonus/checker_bonus.h
				
CFLAGS = -Wall -Wextra -Werror -ggdb 
CC = cc

CFILES = ./mandatory/push_swap.c \
		 ./mandatory/sort_algo.c \
		 ./mandatory/check_sorted.c \
		 ./mandatory/big_sort.c \
		 ./mandatory/anthor_check.c
		 
CHELPER = ./utlis/check_min_max.c \
		  ./utlis/ft_check_errors.c \
		  ./utlis/initstack.c \
		  ./utlis/ft_atoi.c \
		  ./utlis/ft_split.c \
		  ./utlis/superlib.c \
		  ./utlis/helpers.c \
		  ./operations/rotate.c \
		  ./operations/swap.c \
		  ./operations/push.c \
		  ./operations/reverse_rotate.c\

C_BONUS = ./checker_bonus/checker.c \
		  ./checker_bonus/get_next_line.c \
		  ./checker_bonus/get_next_line_utlis.c \
		  ./mandatory/check_sorted.c \
		  ./checker_bonus/operting.c \

GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
ENDCOLOR = \033[0m

OBJ = $(CFILES:.c=.o) $(CHELPER:.c=.o)
OBJ_BONUS = $(C_BONUS:.c=.o) $(CHELPER:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@clear
	@bash test.sh
	@clear 
	@echo "${GREEN}\n✅ push swap completed successfully! ✅${ENDCOLOR}"
	
bonus: $(OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_BONUS)
	@clear
	@bash test.sh
	@clear 
	@echo "${GREEN}\n✅ bonus completed successfully! ✅${ENDCOLOR}"
%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@sleep 0.1
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@clear 
	@echo "${RED}🧹 ...Cleaned objetsc!... 🧹${ENDCOLOR}"
	

fclean: clean
	@rm -rf $(NAME) $(BONUS)
	@echo "${RED}🧹 ...Cleaned ALL... 🧹${ENDCOLOR}"

re: fclean all bonus

.PHONY: all clean fclean re
.SILENT:
