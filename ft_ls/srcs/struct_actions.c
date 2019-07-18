/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:03:13 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/18 10:03:15 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*destroy_dir(t_dir *d)
{
	if (d)
	{
		if (d->name)
			free(d->name);
		if (d->childs)
			d->childs = destroy_dir(d->childs);
		if (d->next)
			d->next = destroy_dir(d->child);
		free(d);
	}
	return (NULL);
}

t_dir		*generate_dir(char *name, int type)
{
	t_dir	*d;

	if (!(d = (t_dir *)malloc(sizeof(t_dir))) ||
		!(d->name = ft_strdup(name)))
		return (destroy_dir(d));
	d->next = NULL;
	d->childs = NULL;
	d->type = type;
}

t_global	*generate_global(void)
{
	t_global *g;
	int i;

	if (!(g = (t_global *)malloc(sizeof(t_global))) ||
		!(g->options = (int *)malloc(sizeof(int) * ft_strlen(OPT))))
		print(destroy_global(g), 0, NULL);
	i = -1;
	while (++i < OPT_LEN)
		g->options[i] = 0;
	return (g);
}

t_global	*destroy_global(t_global *g)
{
	if (g)
	{
		if (g->options)
			free(g->options);
		free(g);
	}
	return (NULL);
}
