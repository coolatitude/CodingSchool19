/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 22:12:40 by pvanderl          #+#    #+#             */
/*   Updated: 2019/06/12 23:12:21 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function print_code
**
**	prints the correct codeon the console corresponding with the action
**
**	@param:	the action to print
**
**	@out:	/
*/

void		print_code(int n)
{
	if (n == SA)
		write(1, "sa\n", 3);
	else if (n == SB)
		write(1, "sb\n", 3);
	else if (n == SS)
		write(1, "ss\n", 3);
	else if (n == PA)
		write(1, "pa\n", 3);
	else if (n == PB)
		write(1, "pb\n", 3);
	else if (n == RA)
		write(1, "ra\n", 3);
	else if (n == RB)
		write(1, "rb\n", 3);
	else if (n == RR)
		write(1, "rr\n", 3);
	else if (n == RRA)
		write(1, "rra\n", 4);
	else if (n == RRB)
		write(1, "rrb\n", 4);
	else if (n == RRR)
		write(1, "rrr\n", 4);
}

/*
**	function print
**
**	print tha actions if needed than call and destroy the t_stack elem and exit
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	0
*/

int			print(t_stack *s)
{
	int			i;
	t_action	*action;

	i = 0;
	if (s && !s->checker)
	{
		action = s->actions;
		while (action)
		{
			print_code(action->action);
			action = action->next;
		}
	}
	else if (s && s->checker && s->status != 0)
	{
		if (s->status == 1)
			write(1, "OK\n", 3);
		else if (s->status == 2)
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	s = destroy(s);
	exit(0);
	return (0);
}
