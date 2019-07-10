/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:15:01 by pvanderl          #+#    #+#             */
/*   Updated: 2019/05/28 14:53:46 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function rra
**
**	shift down all the elements from a. the last become the first
**
**	@param:	a pointer on the t_stack
**
**	@out:	/
*/

void	rra(t_stack *s)
{
	int	tmp;
	int	i;

	if (!s->checker)
		add_action(s, RRA);
	i = s->size_a - 1;
	tmp = s->a[i];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = tmp;
}

/*
**	function rrb
**
**	shift down all the elements from b. the last element become the first
**
**	@param:	a pointer on the t_stack
**
**	@out:	/
*/

void	rrb(t_stack *s)
{
	int	tmp;
	int	i;

	if (!s->checker)
		add_action(s, RRB);
	i = s->size_b - 1;
	tmp = s->b[i];
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = tmp;
}

/*
**	function rrr
**
**	do rra and rrb at the same time
**
**	@param:	a pointer on the t_stack
**
**	@out:	/
*/

void	rrr(t_stack *s)
{
	int	tmp;
	int	i;

	if (!s->checker)
		add_action(s, RRR);
	i = s->size_a;
	tmp = s->a[i - 1];
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->a[0] = tmp;
	i = s->size_b;
	tmp = s->b[i - 1];
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->b[0] = tmp;
}
