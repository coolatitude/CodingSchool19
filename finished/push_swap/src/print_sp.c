/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:17:14 by pvanderl          #+#    #+#             */
/*   Updated: 2019/05/28 14:36:12 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function ss
**
**	do sa and sb at the same time
**
**	@param:	a pointer on the t_stack structure
**
**	@out:	/
*/

void	ss(t_stack *s)
{
	int tmp;

	if (!s->checker)
		add_action(s, SS);
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
}

/*
**	function sa
**
**	swap the two first elements of the a stack
**
**	@param:	a pointer on the t_stack structure
**
**	@out:	/
*/

void	sa(t_stack *s)
{
	int tmp;

	if (!s->checker)
		add_action(s, SA);
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
}

/*
**	function sb
**
**	swap the two first elements of the b stack
**
**	@param:	a pointer on the t_stack structure
**
**	@out:	/
*/

void	sb(t_stack *s)
{
	int tmp;

	if (!s->checker)
		add_action(s, SB);
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
}

/*
**	function pa
**
**	take the first element of the b stack and push it on the top of the a stack
**
**	@param:	a pointer on the t_stack structure
**
**	@out:	/
*/

void	pa(t_stack *s)
{
	int	i;

	if (!s->checker)
		add_action(s, PA);
	i = s->size_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = s->b[0];
	while (i < s->size_b - 1)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->size_a++;
	s->size_b--;
}

/*
**	function pb
**
**	take the first element of the a stack and push it on the top of the b stack
**
**	@param:	a pointer on the t_stack structure
**
**	@out:	/
*/

void	pb(t_stack *s)
{
	int	i;

	if (!s->checker)
		add_action(s, PB);
	i = s->size_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = s->a[0];
	while (i < s->size_a - 1)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->size_a--;
	s->size_b++;
}
