/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:17:48 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/27 13:52:13 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print(t_elem *v)
{
	if (v->padc == ' ' && !v->ladjust)
		while (--v->length >= 0)
			putchar_buff(' ', v);
	if (v->sign_char)
		putchar_buff(v->sign_char, v);
	if (v->pref != 0)
		string_to_buff(v->pref, v);
	if (v->padc == '0')
		while (--v->length >= 0)
			putchar_buff('0', v);
	if (v->prec)
		while (v->prec-- > 0)
			putchar_buff('0', v);
	while (++(v->np) != v->nbuf + MAXBUF)
		putchar_buff(*v->np, v);
	if (v->ladjust)
		while (--v->length >= 0)
			putchar_buff(' ', v);
}

void			print_num(t_elem *v, unsigned long long u)
{
	if (v->prec != -1)
		v->padc = ' ';
	if (v->base == 8 && v->altfmt && (u != 0 || (u == 0 && v->prec == 0)) &&
		(v->prec--))
		v->pref = "0";
	if (u != 0 && v->altfmt && v->base == 16)
		v->pref = (v->cap) ? "0X" : "0x";
	if (u == 0 && v->prec != 0)
		*v->np-- = '0';
	while (u != 0)
	{
		*v->np-- = *(v->cs + v->cap + u % v->base);
		u /= v->base;
	}
	if (v->prec)
		v->prec = (v->prec > v->nbuf + MAXBUF - 1 - v->np) ?
			v->prec - (v->nbuf + MAXBUF - 1 - v->np) : 0;
	v->length -= v->nbuf + MAXBUF - 1 - v->np + v->prec;
	if (v->sign_char)
		v->length--;
	if (v->pref)
		v->length -= ft_strlen((const char *)v->pref);
	print(v);
}
