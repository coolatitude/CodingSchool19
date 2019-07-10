/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:32:24 by pvanderl          #+#    #+#             */
/*   Updated: 2019/06/17 12:33:41 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function splita
**
**	this parse the read line to check if the action is known
**
**	@param:	the line read
**	@param:	a pointer on the t_stack elem
**
**	@out:	1 if the action is know | 0 otherwise
*/

int		splita(char *action, t_stack *s)
{
	if (ft_strcmp(action, "rb") == 0)
		rb(s);
	else if (ft_strcmp(action, "rr") == 0)
		rr(s);
	else if (ft_strcmp(action, "rra") == 0)
		rra(s);
	else if (ft_strcmp(action, "rrb") == 0)
		rrb(s);
	else if (ft_strcmp(action, "rrr") == 0)
		rrr(s);
	else
		return (0);
	return (1);
}

/*
**	function splitb
**
**	this parse the read line to check if the action is known
**
**	@param:	the line read
**	@param:	a pointer on the t_stack elem
**
**	@out:	1 if the action is know | 0 otherwise
*/

int		splitb(char *action, t_stack *s)
{
	if (ft_strcmp(action, "pa") == 0)
		pa(s);
	else if (ft_strcmp(action, "pb") == 0)
		pb(s);
	else if (ft_strcmp(action, "sa") == 0)
		sa(s);
	else if (ft_strcmp(action, "sb") == 0)
		sb(s);
	else if (ft_strcmp(action, "ss") == 0)
		ss(s);
	else if (ft_strcmp(action, "ra") == 0)
		ra(s);
	else
		return (0);
	return (1);
}

/*
**	function split
**
**	check the result of the reading and call splita and splitb
**
**	@param:	the line read
**	@param:	a pointer on the t_stack elem
**
**	@out:	an int: 1 if error | 2 if the line is correct | 0 if end of file
*/

int		split(char *action, t_stack *s)
{
	if (!action)
		return (1);
	if (ft_strcmp(action, "EOF") == 0)
		return (0);
	if (splita(action, s) || splitb(action, s))
	{
		free(action);
		return (2);
	}
	else
	{
		free(action);
		return (1);
	}
}

/*
**	function get_line
**
**	this call get_next_line to get a line from the input and returns it
**
**	@param:	/
**
**	@out:	the line read or "EOF" if no more lines
*/

char	*get_line(void)
{
	char	*s;
	int		x;

	x = get_next_line(0, &s);
	if (x == 0)
		return (ft_strdup("EOF"));
	else if (x == 1)
		return (s);
	return (NULL);
}

/*
**	function check_actions
**
**	this will get and check the lines recieved by the pipe
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	/
*/

void	check_actions(t_stack *s)
{
	int a;

	while ((a = split(get_line(), s)))
		if (a == 1)
			break ;
	if (a == 0)
		s->status = (sorted(s) ? 1 : 2);
	else
		s->status = 0;
}
