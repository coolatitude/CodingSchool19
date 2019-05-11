/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 04:06:12 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/23 01:49:03 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			string_buff_n(char *s, int nb, t_elem *v)
{
	int	i;

	i = -1;
	while (s[++i] && i < nb)
		putchar_buff(s[i], v);
	return (i);
}

int			string_to_buff(char *s, t_elem *v)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != '%')
		putchar_buff(s[i], v);
	return (i);
}

void		putchar_buff(char c, t_elem *v)
{
	if (v->bpos >= BUFF_SIZE)
	{
		v->wn += write(1, v->buff, v->bpos);
		v->bpos = 0;
	}
	v->buff[v->bpos] = c;
	v->bpos++;
}

void		putcharn(char c, int nb, t_elem *v)
{
	while (nb-- > 0)
		putchar_buff(c, v);
}

int			ft_putcharn(char c, int nb)
{
	int		x;
	char	s[nb];

	x = -1;
	while (++x < nb)
		s[x] = c;
	return (write(1, s, nb));
}
