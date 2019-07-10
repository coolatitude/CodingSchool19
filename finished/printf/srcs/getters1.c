/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:26:09 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/26 17:17:55 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	function get_zero
**
**	set the zero parameter of the t_elem
*/

void	get_zero(t_elem *v)
{
	if (v->ladjust == FALSE)
		v->padc = '0';
	v->pos++;
}

/*
**	function get_sharp
**
**	set the sharp parameter of the t_elem
*/

void	get_sharp(t_elem *v)
{
	v->altfmt = TRUE;
	(v->pos)++;
}
