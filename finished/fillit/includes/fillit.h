/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:07:26 by pvanderl          #+#    #+#             */
/*   Updated: 2018/12/18 15:39:38 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# define EM '.'
# define BL '#'

typedef struct		s_tetro
{
	char			**piece;
	struct s_tetro	*next;
	int				first_i;
	int				first_j;
	int				last_i;
	int				last_j;
}					t_tetro;
/*
**	from fillit.c
*/

/*
**	from input_tests.c
*/

void				sub_check_form(char **s, int *i);
int					check_form(char **s);
void				addtet(t_tetro **tet, char **s);
t_tetro				*check_and_save_content(int fd);

/*
**	from resolution.c
*/

int					isfitting(t_tetro *elem, char **grid, int i, int j);
void				put_tetro(t_tetro *elem, char **grid, int *i, char c);
void				remove_tetro(t_tetro *elem, char **grid, int i, int j);
int					backtracking(t_tetro *elem, int len, char **grid, char c);
void				resolve(t_tetro *elem);

/*
**	from tools.c
*/

t_tetro				*t_tetro_new(char **s);
void				t_tetro_add(t_tetro **tet, t_tetro *tetro);
t_tetro				*custom_free(t_tetro *elem);
int					free_table(char ***fr);
int					table_len(char **s);

/*
**	from tools2.c
*/

int					print_grid(char **grid, int len);
char				**blank_grid(int len);

#endif
