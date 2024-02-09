# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 23:35:46 by ayel-mou          #+#    #+#              #
#    Updated: 2024/02/07 03:39:44 by ayel-mou         ###   ########.fr        #
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

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${YELLOW}\n🚀✨ Start of program compilation ✨🚀${ENDCOLOR}"
	sleep 0.1
	@echo "${CYAN}🚀.waiting.📁🚀${YELLOW}"
	@sleep 0.1
	@echo "${CYAN}🚀..waiting..📁🚀${YELLOW}"
	@sleep 0.1
	@echo "${CYAN}🚀...waiting...📁🚀${YELLOW}"
	@sleep 0.1
	@echo "${CYAN}🚀....waiting....📁🚀${YELLOW}"
	@sleep 0.1
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@clear
	@echo "${GREEN}\n✅ completed successfully! ✅${ENDCOLOR}"

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${CYAN}🚀.Cleaning.🧹🚀${YELLOW}"
	@sleep 0.1
	@echo "${CYAN}🚀..Cleaning..🧹🚀${YELLOW}"
	@sleep 0.1
	@echo "${CYAN}🚀...Cleaning...🧹🚀${YELLOW}"
	@sleep 0.1
	@echo "${CYAN}🚀....Cleaning....🧹🚀${YELLOW}"
	@sleep 0.1
	@rm -rf $(OBJ)
	@echo "${RED}🧹 ...Cleaned objetsc!... 🧹${ENDCOLOR}"

fclean: clean
	@rm -rf $(NAME)
	@echo "${RED}🧹 ...Cleaned $(NAME)!... 🧹${ENDCOLOR}"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
