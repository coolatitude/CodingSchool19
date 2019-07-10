/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 22:53:36 by pvanderl          #+#    #+#             */
/*   Updated: 2019/06/12 23:22:29 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function get_median
**
**	return the median of n elements of a stack
**
**	@param:	a pointer on the start of the segment
**	@param:	the size of the segment
**
**	@out:	the median of the segment
*/

int		get_median(int *s, int nb)
{
	int	n;
	int d;
	int	de;
	int	i;

	n = 0;
	de = delta(s, nb, *s);
	i = 1;
	while (i < nb)
	{
		d = delta(s, nb, *(s + i));
		if (d < de)
		{
			n = i;
			de = d;
		}
		i++;
	}
	return (*(n + s));
}

/*
**	function change_two_by_two
**
**	does the corrects operations to sort and regroup the 2 firsts
**	elements of a and b on a in the order
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	/
*/

void	change_two_by_two(t_stack *s)
{
	if (s->sa == 2 && s->size_sb && s->sb[0] == 2 && s->a[1] < s->a[0])
		sa(s);
	if ((s->size_sb && (s->sb[0] == 2 && s->sa < 2)) ||
			(s->sa == 2 && s->sb[0] == 2))
	{
		if (s->b[0] < s->b[1])
			sb(s);
		pa(s);
		pa(s);
	}
	else if (s->sa == 2 && s->size_sb && s->sb[0] < 2)
	{
		if (s->a[1] < s->a[0])
			sa(s);
		if (s->sb[0] == 1)
			pa(s);
	}
	else if (s->size_sb && s->sb[0] == 1)
		pa(s);
	pop(s);
	s->sa = 0;
}

/*
**	function move_a
**
**	moves the elements smaller than the median from a to b
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	/
*/

void	move_a(t_stack *s)
{
	int	med;
	int	i;
	int	count;

	med = get_median(s->a, s->sa);
	i = 0;
	count = 0;
	while (i < s->sa)
	{
		if (s->a[0] < med)
		{
			count++;
			pb(s);
		}
		else
			ra(s);
		i++;
	}
	while (i-- > count)
		rra(s);
	s->sa -= count;
	push(s, count);
	if (s->sa > 2)
		move_a(s);
}

/*
**	function move_b
**
**	moves the elements greater than the median from b to a
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	/
*/

void	move_b(t_stack *s)
{
	int	med;
	int	i;
	int	count;

	med = get_median(s->b, s->sb[0]);
	i = -1;
	count = 0;
	while (++i < s->sb[0])
	{
		if (s->b[0] > med)
		{
			count++;
			pa(s);
		}
		else
			rb(s);
	}
	if (s->size_sb > 1 && i > count)
		while (i-- > count)
			rrb(s);
	s->sb[0] -= count;
	s->sa = count;
	if (s->sa > 2)
		move_a(s);
}

/*
**	function sort
**
**	move the elements below the median from b to a or from a to b
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	/
*/

void	sort(t_stack *s)
{
	s->sa = s->size_a;
	move_a(s);
	while (s->size_sb > 0)
	{
		if (s->sb[0] < 3 && s->sa < 3)
			change_two_by_two(s);
		else if (s->sa == 0)
			move_b(s);
		else
			move_a(s);
	}
	if (s->a[1] < s->a[0])
		sa(s);
}
