/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:03:02 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/18 10:03:04 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_valid_option(char c)
{
	int i;

	i = -1;
	while (OPT[++i])
		if (OPT[i] == c)
			return (i);
	return (-1);
}

int		options(t_global *g, char *s)
{
	int i;
	int	pos;

	i = 0;
	if (ft_strlen(s) > 1 && s[0] == '-')
	{
		while (*(++s))
			if ((pos = is_valid_option(*s)) >= 0)
				g->options[pos] = 1;
			else
				print(destroy_global(g), *s, NULL);
		return (1);
	}
	else
		return (0);
}
