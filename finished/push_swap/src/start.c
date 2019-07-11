/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:24:15 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/11 14:20:41 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function start
**
**	call sort if the entries are correct and not sorted
*/

int		start(int ac, char **av, int checker)
{
	t_stack	*s;

	s = generate(ac, checker);
	if (ac > 0 && s)
	{
		while (s && s->size_a < ac)
			if (!check(av[s->size_a]) || !add(s, ft_atoi(av[s->size_a])))
				s = destroy(s);
		if (s && s->checker)
			check_actions(s);
		else if (s && !s->checker)
		{
			if (!(sorted(s)))
			{
				sort(s);
				while (optimise(s))
					;
			}
		}
		else if (s)
			s = destroy(s);
	}
	return (print(s));
}
