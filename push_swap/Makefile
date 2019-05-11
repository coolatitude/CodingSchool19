# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 20:03:57 by pvanderl          #+#    #+#              #
#    Updated: 2019/02/26 20:34:53 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = push_swap

NAME1 = checker

CC = gcc

INCLUDES = ./includes/

SRCSDIR = ./srcs/

#CFLAGS = -Wall -Wextra -Werror

SRCS1 = checker

SRCS2 = push_swap

CLIBFT = -I${LIBFT}/includes

COPTIONS = -c -I$(INCLUDES) $(CLIBFT)

OBJS1 = $(addprefix ./$(NAME1)/srcs/, $(addsuffix .o, $(SRCS1)))

OBJS2 = $(addprefix ./$(NAME2)/srcs/, $(addsuffix .o, $(SRCS2)))

all: $(NAME)

$(NAME): libft $(NAME1) $(NAME2)
#	@clear
	@python launch.py | cat -e

$(NAME1): libft
	@echo $(NAME1)

$(OBJS1): %.o:%.c
	@$(CC) $(CFLAGS) $(COPTIONS) $^ -o $@

$(NAME2):
	@echo $(NAME2)

$(OBJS2): %.o:%.c
	@$(CC) $(CFLAGS) $(COPTIONS) $^ -o $@

libft:
	@Make -C ${LIBFT}/

clear:
	@clear

clean:
	#@make -C ${LIBFT}/ fclean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean re fclean
