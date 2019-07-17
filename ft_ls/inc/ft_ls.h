#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_global
{
	char		*options;
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

t_global		*generate_global(void);
t_global		*destroy_global(t_global *g);

/*
**	print
**	1 function
*/

void			print(t_global *g);

#endif
