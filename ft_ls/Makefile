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

NAME = ft_ls

CC = gcc

INCLUDES = ./inc/

SRCSDIR = ./srcs/

CFLAGS = -Wall -Wextra -Werror

SRCS = main options struct_actions print

CLIBFT = -I${LIBFT}/includes

COPT = -I$(INCLUDES) $(CLIBFT) -L${LIBFT}/ -l ft

OBJS = $(addprefix $(SRCSDIR), $(addsuffix .c, $(SRCS)))

all: $(NAME)

$(NAME): libft
	@$(CC) $(CFLAGS) $(OBJS) $(COPT) -o $(NAME)

libft: clear
	@Make -C ${LIBFT}/

clear:
	@clear

clean:
	@make -C ${LIBFT}/ fclean

norm:
	@norminette $(INCLUDES) ${LIBFT}/includes/*
	@norminette ${LIBFT}/srcs/*
	@norminette $(OBJS)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: clean re fclean
