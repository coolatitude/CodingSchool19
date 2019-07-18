/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:42:26 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/18 10:42:28 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include "ft_printf.h"

/*
** L R a r t
*/

# define OPT_LEN 3
# define OPT "a"

/*
**	L. stands for lowercase letter
*/

# define LA 1


typedef struct	s_dir	t_dir;

struct			s_dir
{
	char		*name;
	t_dir		*childs;
	t_dir		*next;
	int			type;
};

typedef struct	s_global
{
	int			*options;
	t_dir		*dirs;
}				t_global;

/*
**	options
**
*/

int				options(t_global *g, char *s);

/*
**	struct_actions
**	2 functions
*/

t_dir			*generate_dir(char *name, int type);
t_dir			*destroy_dir(t_dir *d);
t_global		*generate_global(void);
t_global		*destroy_global(t_global *g);

/*
**	print
**	1 function
*/

void			print(t_global *g, int c, char *dir);

/*
**	dirs
**	1 function
*/

void			add_dir(t_global *g, char *dname);

#endif
