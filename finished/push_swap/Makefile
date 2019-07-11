# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 20:03:57 by pvanderl          #+#    #+#              #
#    Updated: 2019/07/11 15:30:55 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = common

NAME2 = checker

NAME1 = push_swap

CC = gcc

INCLUDES = ./inc/

SRCSDIR = ./src/

CFLAGS = -Wall -Wextra -Werror

SRCSCOM = input_tools print_r print_rr print_sp se_tools sorting sorting_next\
		struct_actions optimisation check_actions start 

SRCS1 = p_main

SRCS2 = c_main

CLIBFT = -I${LIBFT}/includes

COPT = -I$(INCLUDES) $(CLIBFT) -L${LIBFT}/ -l ft

OCOM = $(addprefix $(SRCSDIR), $(addsuffix .c, $(SRCSCOM)))

OBJS1 = $(addprefix $(SRCSDIR), $(addsuffix .c, $(SRCS1)))

OBJS2 = $(addprefix $(SRCSDIR), $(addsuffix .c, $(SRCS2)))

all: $(NAME)

$(NAME): $(NAME1) $(NAME2)
	@echo "Make OK"

$(NAME1): libft
	@$(CC) $(CFLAGS) $(OBJS1) $(OCOM) $(COPT) -o $(NAME1)

$(NAME2): libft
	@$(CC) $(CFLAGS) $(OBJS2) $(OCOM) $(COPT) -o $(NAME2)

libft: clear
	@Make -C ${LIBFT}/

clear:
	@clear

clean:
	@make -C ${LIBFT}/ fclean

norm:
	@norminette $(INCLUDES) ${LIBFT}/includes/*
	@norminette ${LIBFT}/srcs/*
	@norminette $(OCOM) $(OBJS1) $(OBJS2)

fclean: clean
	@rm $(NAME1) $(NAME2)

re: fclean all

.PHONY: clean re fclean
