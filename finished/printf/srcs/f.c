/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:24:51 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/23 04:28:13 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_pre(t_elem *v, long double t, char *s)
{
	int i;

	i = -1;
	while (++i < v->prec + 1)
	{
		t = (t - (double)(long long int)t) * 10;
		s[i] = *(v->cs + (int)t % 10);
	}
	if (s[v->prec - 1] != '9' && s[v->prec] >= '5')
		s[v->prec - 1]++;
	else if (s[v->prec] >= '5')
	{
		i = 1;
		while (s[v->prec - i] == '9')
			s[v->prec - i++] = '0';
		s[v->prec - i]++;
	}
	return (s);
}

static void		print(t_elem *v, long double t)
{
	char x[50];

	if (v->padc == ' ' && !v->ladjust)
		while (--v->length >= 0)
			putchar_buff(' ', v);
	if (v->sign_char)
		putchar_buff(v->sign_char, v);
	if (v->padc == '0')
		while (--v->length >= 0)
			putchar_buff('0', v);
	while (++(v->np) != v->nbuf + MAXBUF)
		putchar_buff(*v->np, v);
	if (v->prec || v->altfmt)
		putchar_buff('.', v);
	if (v->prec > 0)
		string_buff_n(get_pre(v, t, &x[0]), v->prec, v);
	if (v->ladjust)
		while (--v->length >= 0)
			putchar_buff(' ', v);
}

static void		print_n(t_elem *v, double u, double t)
{
	if (u <= 1)
		*v->np-- = '0';
	while (u >= 1)
	{
		*v->np-- = *(v->cs + (long long int)u % v->base);
		u /= v->base;
	}
	v->length -= v->nbuf + MAXBUF - 1 - v->np + v->prec +
		((v->prec || v->altfmt) ? 1 : 0);
	if (v->sign_char)
		v->length--;
	print(v, t);
}

int				ft_printf_f(double nb, t_elem *v)
{
	if (v->prec == -1)
		v->prec = 6;
	if (nb >= 0)
		v->sign_char = v->plus_sign;
	else
	{
		v->sign_char = '-';
		nb = -nb;
	}
	print_n(v, nb, nb);
	v->pos++;
	return (0);
}
