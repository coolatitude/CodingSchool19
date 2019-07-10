/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lh_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:50:01 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/23 00:55:55 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getj(t_elem *v)
{
	v->mod = 6;
	v->pos++;
}

void	ft_gett(t_elem *v)
{
	v->mod = 7;
	v->pos++;
}

void	ft_getz(t_elem *v)
{
	v->mod = 8;
	v->pos++;
}
