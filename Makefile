# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/27 16:30:17 by pvanderl          #+#    #+#              #
#    Updated: 2019/07/02 09:53:25 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = generic

msg = change computer

branch = master

$(NAME): clean
	@find * -name Makefile -execdir make fclean \;
	@git add -A
	@echo "added"
	@git commit -m "$(msg)"
	@git push origin $(branch)

clean:
	@find . -name "*.swp" -exec rm -f {} +
	@find . -name ".DS_Store" -exec rm -f {} +
	@find . -name ".o" -exec rm -f {} +
	@find . -name ".vscode" -exec rm -rf {} +

fclean:
	@find */. -name Makefile -execdir make fclean \;
	@echo "OK"
