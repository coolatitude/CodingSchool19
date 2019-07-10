/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:39:48 by pvanderl          #+#    #+#             */
/*   Updated: 2019/06/12 22:52:52 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function remove_one
**
**	remove correctly an action in the chained list of actions
**
**	@param:	a pointer on the t_action before the one to remove
**
**	@out:	/
*/

void	remove_one(t_action *a)
{
	t_action	*tmp;

	tmp = a->next;
	a->next = a->next->next;
	tmp->next = NULL;
	free(tmp);
}

/*
**	function match_n_match
**
**	check if two actions matches
**
**	@param:	the first action
**	@param:	the second action
**
**	@out:	1 if those matche | 0 if not
*/

int		match_n_match(int a, int b)
{
	return ((a == PB && b == PA) || (a == PA && b == PB) ||
			(a == RA && b == RRA) || (a == RRA && b == RA) ||
			(a == RB && b == RRB) || (a == RRB && b == RB));
}

/*
**	function optimise
**
**	remove all the actions / group of actions that are useless
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	0 if we arrived at the end of the list of actions
**			without removing anything
*/

int		optimise(t_stack *s)
{
	t_action	*current;

	current = s->actions;
	while (current->next)
	{
		if (current->action == -(current->next->action))
		{
			current->action = 10 *
				((current->action < 0) ? -(current->action) : current->action);
			remove_one(current);
			return (1);
		}
		if (current->next->next &&
			match_n_match(current->next->action, current->next->next->action))
		{
			remove_one(current);
			remove_one(current);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
