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

SRCS = main options struct_actions print dirs

CLIBFT = -I${FTPRINTF}/includes -I${LIBFT}/includes

COPT = -I$(INCLUDES) $(CLIBFT) -L${FTPRINTF}/ -l ftprintf -L${LIBFT}/ -l ft

OBJS = $(addprefix $(SRCSDIR), $(addsuffix .c, $(SRCS)))

all: $(NAME)

$(NAME): #libs
	@$(CC) $(CFLAGS) $(OBJS) $(COPT) -o $(NAME)

libs: clear
	@Make -C ${FTPRINTF}/

clear:
	@clear

clean:
	@make -C ${FTPRINTF}/ fclean

norm:
	@norminette $(INCLUDES)
	@norminette $(OBJS)

fclean: #clean
	@rm $(NAME)

re: fclean all

.PHONY: clean re fclean
