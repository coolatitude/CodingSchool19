/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:20:46 by pvanderl          #+#    #+#             */
/*   Updated: 2019/06/12 23:33:34 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function delete_action
**
**	free the last element of the actions' chained list
**
**	@param:	a pointer on the element of the list to delete
**
**	@out:	/
*/

void		delete_action(t_action *a)
{
	if (a->next)
		delete_action(a->next);
	free(a);
}

/*
**	function destroy
**
**	free correctly the t_stack element
**
**	@param:	a pointer on the t_stack element to destroy
**
**	@out:	NULL
*/

t_stack		*destroy(t_stack *s)
{
	if (s)
	{
		if (!s->checker && s->actions)
			delete_action(s->actions);
		if (!s->checker && s->sb)
			free(s->sb);
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		free(s);
	}
	return (NULL);
}

/*
**	function generate
**
**	generate the t_stack elem
**
**	@param:	the number of arguments. aka the max size of a stack
**	@param:	1 if it's the checker program | 0 if it's the push_swap program
**
**	@out:	a pointer on the new t_stack element
*/

t_stack		*generate(int size, int checker)
{
	t_stack	*s;

	if (!(s = (t_stack *)malloc(sizeof(t_stack))) ||
			!(s->a = (int *)malloc(sizeof(int) * size)) ||
			!(s->b = (int *)malloc(sizeof(int) * size)))
		return (destroy(s));
	if (!checker && !(s->sb = (int *)malloc(sizeof(int) * size)))
		return (destroy(s));
	s->actions = NULL;
	s->size_a = 0;
	s->size_b = 0;
	s->size_sb = 0;
	s->status = 0;
	s->checker = checker;
	return (s);
}

/*
**	function add_action
**
**	add an action element at the end of the actions' chained list
**
**	@param:	a pointer on the t_stack elem
**	@param:	the code of the action to add
**
**	@out:	/
*/

void		add_action(t_stack *s, int n)
{
	t_action	*tmp;
	t_action	*elem;

	if (!(elem = (t_action *)malloc(sizeof(t_action))))
	{
		s = destroy(s);
		print(s);
	}
	elem->action = n;
	elem->next = NULL;
	if (!(s->actions))
		s->actions = elem;
	else
	{
		tmp = s->actions;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}
