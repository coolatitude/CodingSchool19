/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lh_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:50:01 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/23 00:55:10 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_gethh(t_elem *v)
{
	v->mod = 1;
	v->pos += 2;
}

void	ft_geth(t_elem *v)
{
	v->mod = 2;
	v->pos++;
}

void	ft_getbigl(t_elem *v)
{
	v->mod = 3;
	v->pos++;
}

void	ft_getl(t_elem *v)
{
	v->mod = 4;
	v->pos++;
}

void	ft_getll(t_elem *v)
{
	v->mod = 5;
	v->pos += 2;
}
