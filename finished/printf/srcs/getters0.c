/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:42:27 by pvanderl          #+#    #+#             */
/*   Updated: 2019/03/14 09:09:21 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	function get_fwidth
**
**	set the fwidth parameter of the t_elem
*/

void	get_fwidth(char *s, t_elem *v, va_list ap)
{
	if (*(s + v->pos) == '*')
	{
		v->length = va_arg(ap, int);
		v->pos++;
	}
	else
	{
		v->length = ft_atoi(s + v->pos);
		while (ft_isdigit(*(s + v->pos)))
			(v->pos)++;
	}
	if (v->length < 0)
	{
		v->ladjust = !v->ladjust;
		v->length = -v->length;
	}
}

/*
**	function get_dot
**
**	set the dot parameter of the t_elem
*/

void	get_dot(char *s, t_elem *v, va_list ap)
{
	v->prec = 0;
	v->pos++;
	if (*(s + v->pos) == '*')
	{
		v->prec = va_arg(ap, int);
		if (v->prec < 0)
			v->prec = -1;
		(v->pos)++;
	}
	else if (ft_isdigit(*(s + v->pos)))
	{
		while (ft_isdigit(*(s + v->pos)))
			v->prec = v->prec * 10 + *(s + v->pos++) - '0';
	}
}

/*
**	function get_minus
**
**	set the minus parameter of the t_elem
*/

void	get_minus(t_elem *v)
{
	v->ladjust = TRUE;
	v->padc = ' ';
	v->pos++;
}

/*
**	function get_plus
**
**	set the plus parameter of the t_elem
*/

void	get_plus(t_elem *v)
{
	v->plus_sign = '+';
	v->pos++;
}

/*
**	function get_space
**
**	set the plus parameter of the t_elem if not set
*/

void	get_space(t_elem *v)
{
	if (v->plus_sign == 0)
		v->plus_sign = ' ';
	v->pos++;
}
