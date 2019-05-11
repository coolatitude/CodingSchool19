/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:31:27 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/27 11:46:13 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse2_1(char *s, t_elem *v, va_list ap)
{
	char c;

	c = *(s + v->pos);
	if (c == 'f' || c == 'F')
		return (ft_printf_f(va_arg(ap, double), v));
	else if (c == 'U' && (v->mod = 4))
		return (ft_printf_u(ap, v));
	else if (c == 'n')
		return (n(ap, v));
	return (-1);
}

static int	parse2(char *s, t_elem *v, va_list ap)
{
	char c;

	c = *(s + v->pos);
	if (c == '%')
		return (ft_printf_percent(v));
	else if (c == 'c' || c == 'C')
		return (fc(va_arg(ap, int), v));
	else if (c == 's' || c == 'S')
		return (fs(va_arg(ap, char *), v));
	else if (c == 'd' || c == 'i')
		return (ft_printf_d(ap, v));
	else if (c == 'p')
		return (p(va_arg(ap, void *), v));
	else if (c == 'o')
		return (ft_printf_o(ap, v));
	else if (c == 'u')
		return (ft_printf_u(ap, v));
	else if (c == 'x')
		return (ft_printf_x(ap, v));
	else if (c == 'X' && (v->cap = CAP))
		return (ft_printf_x(ap, v));
	return (parse2_1(s, v, ap));
}

static int	parse1(char *s, t_elem *v, va_list ap)
{
	char c;

	if (*(s + v->pos) == '.')
		get_dot(s, v, ap);
	c = *(s + v->pos);
	if (c == 'h' && *(s + 1 + v->pos) == 'h')
		ft_gethh(v);
	else if (c == 'h')
		ft_geth(v);
	else if (c == 'l' && *(s + 1 + v->pos) == 'l')
		ft_getll(v);
	else if (c == 'l')
		ft_getl(v);
	else if (c == 'L')
		ft_getbigl(v);
	else if (c == 'j')
		ft_getj(v);
	else if (c == 't')
		ft_gett(v);
	else if (c == 'z')
		ft_getz(v);
	return (parse2(s, v, ap));
}

int			parse(char *s, t_elem *v, va_list ap)
{
	char c;

	c = *(s + v->pos);
	if (c == '#')
		get_sharp(v);
	else if (c == '0')
		get_zero(v);
	else if (c == '-')
		get_minus(v);
	else if (c == ' ')
		get_space(v);
	else if (*(s + v->pos) == '+')
		get_plus(v);
	else if ((c != '0' && ft_isdigit(c)) || c == '*')
		get_fwidth(s, v, ap);
	else
		return (parse1(s, v, ap));
	return (parse(s, v, ap));
}
