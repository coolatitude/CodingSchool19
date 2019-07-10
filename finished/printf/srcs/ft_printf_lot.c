/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:08:23 by pvanderl          #+#    #+#             */
/*   Updated: 2019/03/14 09:38:49 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fs(char *s, t_elem *v)
{
	int		len;

	if (!s)
		s = "(null)";
	v->pos++;
	len = (int)ft_strlen(s);
	v->prec = (v->prec == -1 || v->prec > len) ? len : v->prec;
	v->length = (v->length == -1) ? v->prec : v->length;
	if (!v->ladjust)
		putcharn(v->padc, v->length - v->prec, v);
	string_buff_n(s, v->prec, v);
	if (v->ladjust)
		putcharn(v->padc, v->length - v->prec, v);
	return (0);
}

int		ft_printf_percent(t_elem *v)
{

	v->pos++;
	v->prec = (v->prec == -1 || v->prec > 1) ? 1 : v->prec;
	v->length = (v->length == -1) ? v->prec : v->length;
	if (!v->ladjust)
		putcharn(v->padc, v->length - v->prec, v);
	putchar_buff('%', v);
	if (v->ladjust)
		putcharn(v->padc, v->length - v->prec, v);
	return (0);
}

int		fc(int c, t_elem *v)
{
	if (!v->ladjust)
		putcharn(v->padc, v->length - 1, v);
	putchar_buff(c, v);
	if (v->ladjust)
		putcharn(v->padc, v->length - 1, v);
	(v->pos)++;
	return (0);
}

int		d(long long int nb, t_elem *v)
{
	v->pos++;
	v->base = 10;
	if (nb >= 0)
	{
		v->sign_char = v->plus_sign;
		print_num(v, nb);
	}
	else
	{
		v->sign_char = '-';
		print_num(v, -nb);
	}
	return (0);
}

int		p(void *p, t_elem *v)
{
	v->pos++;
	v->base = 16;
	v->altfmt = TRUE;
	if (p == 0)
		v->pref = "0x";
	print_num(v, (unsigned long)p);
	return (0);
}
