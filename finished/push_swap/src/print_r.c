/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:15:01 by pvanderl          #+#    #+#             */
/*   Updated: 2019/05/28 14:28:52 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function ra
**
**	shift up all the elements in a. the first become the last
**
**	@param:	a pointer on the t_stack
**
**	@out:	/
*/

void	ra(t_stack *s)
{
	int		i;
	int		tmp;

	if (!s->checker)
		add_action(s, RA);
	i = 0;
	tmp = s->a[0];
	while (i < s->size_a - 1)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
}

/*
**	function rb
**
**	shift up all the elements in b. the first become the last
**
**	@param:	a pointer on the t_stack
**
**	@out:	/
*/

void	rb(t_stack *s)
{
	int		i;
	int		tmp;

	if (!s->checker)
		add_action(s, RB);
	i = 0;
	tmp = s->b[0];
	while (i < s->size_b - 1)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = tmp;
}

/*
**	function rr
**
**	do ra and rb at the same time
**
**	@param:	a pointer on the t_stack
**
**	@out:	/
*/

void	rr(t_stack *s)
{
	int		i;
	int		tmp;

	if (!s->checker)
		add_action(s, RR);
	i = 0;
	tmp = s->a[0];
	while (i < s->size_a - 1)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
	i = 0;
	tmp = s->b[0];
	while (i < s->size_b - 1)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = tmp;
}
