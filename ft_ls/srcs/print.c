/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:03:08 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/18 10:03:10 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_content(t_global *g)
{
	int i;

	i = -1;
	while (++i < OPT_LEN)
		ft_printf("%c: %d\n", OPT[i], g->options[i]);
}

/*
**	TODO: sortie d'erreur au lieu de standard
*/

/*
**	error c > 47:
**		unknown arg c
**	error c == 1:
**		unknown dir
**	no error c == 0:
*/

void		print(t_global *g, int c, char *dir)
{
	if (c > 47)
	{
		ft_printf("ft_ls: illegal option -- %c\n", c);
		ft_printf("usage: ft_ls [-%s] [file ...]\n", OPT);
		exit(0);
	}
	else if (c == 1)
		ft_printf("ft_ls: %s: No such file or directory\n", dir);
	else if (c == 0)
	{
		if (g)
			print_content(g);
		else
			ft_printf("malloc error\n");
		destroy_global(g);
		exit(0);
	}

}
