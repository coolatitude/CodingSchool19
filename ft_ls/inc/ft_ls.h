#ifndef FT_LS_H
# define FT_LS_H

typedef struct	s_global
{
	char		*options;
}				t_global;

/*
**	options
**
*/

int				options(t_global *g, char *s);

#endif
