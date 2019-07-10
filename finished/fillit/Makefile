# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 20:38:46 by pvanderl          #+#    #+#              #
#    Updated: 2019/02/05 15:21:39 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCSDIR = ./srcs/

SRCS = fillit input_tests resolution tools tools2

INCLUDESDIR = ./includes/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

COPTIONS = -I$(INCLUDESDIR) -I${LIBFT}/includes -L${LIBFT} -lft

all:$(NAME)

OBJC = $(addprefix $(SRCSDIR), $(addsuffix .c, $(SRCS)))

$(NAME): $(OBJC)
	@make -C ${LIBFT}/
	@$(CC) $(CFLAGS) $(OBJC) $(COPTIONS) -o $(NAME)
	@echo "compilation \033[1;36mfillit\033[0;m finished"

clean:
	@make -C ${LIBFT}/ fclean
	@echo "clean \033[1;31mfillit\033[0;m finished"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
