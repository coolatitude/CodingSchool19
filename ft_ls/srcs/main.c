/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:02:57 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/18 10:02:59 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_global	*g;

	g = generate_global();
	if (ac > 1)
	{
		av++;
		while (--ac > 0 && options(g, *av))
			av++;
		while (ac-- > 0)
			add_dir(g, *(av++));
	}
	print(g, 0, NULL);
}
