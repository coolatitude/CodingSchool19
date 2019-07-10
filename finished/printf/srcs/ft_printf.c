/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:28:06 by pvanderl          #+#    #+#             */
/*   Updated: 2019/03/14 09:38:59 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			reset(t_elem *values)
{
	values->altfmt = FALSE;
	values->cap = 0;
	values->base = 10;
	values->sign_char = 0;
	values->ladjust = FALSE;
	values->padc = ' ';
	values->plus_sign = 0;
	values->prec = -1;
	values->length = 0;
	values->np = values->nbuf + MAXBUF - 1;
	values->wg = 0;
	values->pos = 0;
	values->mod = 0;
	values->pref = 0;
}

static t_elem		*m(void)
{
	t_elem *v;

	if (!(v = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	if (!(v->buff = (char *)malloc(sizeof(char) * BUFF_SIZE)) ||
		!(v->nbuf = (char *)malloc(sizeof(char) * MAXBUF)))
	{
		free(v);
		return (NULL);
	}
	v->cs = "0123456789abcdef0123456789ABCDEF";
	v->wn = 0;
	v->bpos = 0;
	return (v);
}

int					ft_printf(const char *format, ...)
{
	int				count;
	char			*s;
	va_list			ap;
	t_elem			*v;

	if (!(v = m()))
		return (-1);
	s = (char *)format;
	count = 0;
	va_start(ap, format);
	while (*s)
	{
		reset(v);
		s += string_to_buff(s, v);
		if (*s == '%')
			parse(++s, v, ap);
		s += v->pos;
	}
	count = v->wn + write(1, v->buff, v->bpos);
	free(v->buff);
	free(v->nbuf);
	free(v);
	va_end(ap);
	return (count);
}
