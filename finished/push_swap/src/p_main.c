/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:28:16 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/11 14:19:46 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function main
**
**	main of the push_swap program
*/

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_strsplit(av[1], ' ');
		ac = tablen(av);
		start(ac, av, 0);
		tabfree(av);
	}
	else if (ac > 2)
		start(ac - 1, av + 1, 0);
	return (0);
}
