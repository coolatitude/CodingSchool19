/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:51:21 by pvanderl          #+#    #+#             */
/*   Updated: 2019/06/17 17:13:46 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_s_c.h"

/*
**	function check
**
**	check if the given argument is correct: if it's a correct integer
**
**	@param:	the string to analyze
**
**	@out:	1 if the argument is an integer | 0 if not
*/

int		check(char *s)
{
	long int	i;
	int			sign;

	sign = 1;
	i = 0;
	if (*s == '+')
		s++;
	if (*s == '-')
	{
		s++;
		sign = -1;
	}
	while (ft_isdigit(*s))
	{
		i *= 10;
		i += (*s - '0');
		s++;
	}
	i *= sign;
	if (*s == '\0' && i <= 2147483647 && i >= -2147483648)
		return (1);
	return (0);
}

/*
**	function add
**
**	check if the element is in the stack A and , if not, add it at the end
**
**	@param:	a pointer on the t_stack elem
**	@param:	the number o add
**
**	@out:	1 if the number is well added | 0 if the number is already
**	in the stack
*/

int		add(t_stack *s, int e)
{
	int	i;

	i = -1;
	while (++i < s->size_a)
		if (e == s->a[i])
			return (0);
	s->a[s->size_a] = e;
	(s->size_a)++;
	return (1);
}

/*
**	function sorted
**
**	check if the elements are all on the stack a and if this stack is correctly
**	sorted
**
**	@param:	a pointer on the t_stack elem
**
**	@out:	1 if the a stack is sorted and all the elemments are on the a stack
**			| 0 otherwise
*/

int		sorted(t_stack *s)
{
	int		i;

	if (s->size_b > 0)
		return (0);
	i = s->size_a;
	while (--i > 0)
		if (s->a[i] < s->a[i - 1])
			return (0);
	return (1);
}

/*
**	function tablen
**
**	return the len of a char ** tab
**
**	@param:	a char * table
**
**	@out:	the len of the char * table
*/

int		tablen(char **s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

/*
**	function tabfree
**
**	free a table of char *
**
**	@param:	a table of char *
**
**	@out:	/
*/

void	tabfree(char **s)
{
	int	i;

	i = tablen(s);
	while (--i >= 0)
		free(s[i]);
	free(s);
}
