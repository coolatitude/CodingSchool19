# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 20:03:57 by pvanderl          #+#    #+#              #
#    Updated: 2019/03/26 10:11:46 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

INCLUDES = ./includes/

SRCSDIR = ./srcs/

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf parsing subparsing tools\
		ft_printf_lot getters0 getters1\
		ft_set_lh_flag ft_set_lh_flag2 print_num f

CLIBFT = -I${LIBFT}/includes

COPTIONS = -c -I$(INCLUDES) $(CLIBFT)

OBJS = $(addprefix $(SRCSDIR), $(addsuffix .o, $(SRCS)))

all: $(NAME)

$(NAME): clear $(OBJS)
	@make -C ${LIBFT}/
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS): %.o:%.c
	@$(CC) $(CFLAGS) $(COPTIONS) $^ -o $@

clear:
	@clear

clean:
	@make -C ${LIBFT}/ fclean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean re fclean
