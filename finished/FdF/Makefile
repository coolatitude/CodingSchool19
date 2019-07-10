# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 15:56:11 by pvanderl          #+#    #+#              #
#    Updated: 2019/02/05 15:06:54 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MINILIBDIR = ./minilibx/ 

SRCSDIR = ./srcs/

SRCS = main tools input window calculs\
	   hook draw drawline\
	   imagetools hsv_rgb image_tools range draw_colors

IDIR = -I./includes/

LIBFTI = -I ${LIBFT}/includes
LIB = -L ${LIBFT} -l ft

MLIBXI = -I ./minilibx
MLIBX = -L ./minilibx -l mlx -framework OpenGL -framework AppKit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

COPTIONS = $(IDIR) $(LIBFTI) $(MLIBXI) $(LIB) $(MLIBX)

msg = 19

all:$(NAME)

OBJC = $(addprefix $(SRCSDIR), $(addsuffix .c, $(SRCS)))

$(NAME): $(OBJC)
	@make -C minilibx/
	@make -C ${LIBFT}/
	@clear
	@$(CC) $(CFLAGS) $(OBJC) $(COPTIONS) -o $(NAME)
	@echo "make OK"

clean:
	@find . -name "*.o" -exec rm {} +
	@make -C ${LIBFT}/ clean

fclean:
	@find . -name "*.o" -exec rm {} +
	@make -C ${LIBFT}/ fclean
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@clear
	./fdf ./map/$(msg).fdf

.PHONY: clean re fclean
