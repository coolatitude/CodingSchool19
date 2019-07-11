/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:37:16 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/11 15:22:51 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function delta
**
**	return the difference between the amounts of elements greater and lower
**	than n in the segment
**
**	@param:	the start of the segment
**	@param:	the size of the stack
**	@param:	the reference number
**
**	@out:	the delta of grater and lower numbers from n in the segment
*/

int		delta(int *stack, int nb, int n)
{
	int diff;
	int	i;

	i = 0;
	diff = 0;
	while (i < nb)
	{
		if (stack[i] > n)
			diff++;
		else if (stack[i] < n)
			diff--;
		i++;
	}
	diff = (diff < 0) ? -diff : diff;
	return (diff);
}

/*
**	function push
**
**	add an element at the top of b
**
**	@param:	a pointer on the t_stack elem
**	@param:	the number to add
**
**	@out:	/
*/

void	push(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < s->size_sb)
	{
		s->sb[s->size_sb - i] = s->sb[s->size_sb - i - 1];
		i++;
	}
	s->sb[0] = n;
	s->size_sb++;
}

/*
**	function pop
**
**	move all the elements up ignoring the first one
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	/
*/

void	pop(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size_sb - 1)
	{
		s->sb[i] = s->sb[i + 1];
		i++;
	}
	(s->size_sb)--;
}

/*
**	function less_than_three
**
**	deal with a stack with less than 4 elements
**
**	@param:	a pointer on the t_stack structure
**
**	@out:	/
*/

void	less_than_three(t_stack *s)
{
	if (s->sa == 2)
		sa(s);
	else
	{
		if (s->a[2] > s->a[1] && s->a[2] > s->a[0])
			sa(s);
		else if (s->a[1] > s->a[0] && s->a[1] > s->a[2])
		{
			rra(s);
			if (s->a[0] > s->a[1])
				sa(s);
		}
		else if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
		{
			ra(s);
			if (s->a[0] > s->a[1])
				sa(s);
		}
	}
}
