/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:57:53 by pvanderl          #+#    #+#             */
/*   Updated: 2019/03/05 18:47:33 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_d(va_list ap, t_elem *v)
{
	if (v->mod == 1)
		return (d((signed char)va_arg(ap, int), v));
	else if (v->mod == 2)
		return (d((short int)va_arg(ap, int), v));
	else if (v->mod == 4)
		return (d(va_arg(ap, long int), v));
	else if (v->mod == 5)
		return (d(va_arg(ap, long long int), v));
	else if (v->mod == 6)
		return (d(va_arg(ap, intmax_t), v));
	else if (v->mod == 7)
		return (d(va_arg(ap, ptrdiff_t), v));
	else if (v->mod == 8)
		return (d(va_arg(ap, ssize_t), v));
	else
		return (d(va_arg(ap, int), v));
}

int		ft_printf_x(va_list ap, t_elem *v)
{
	v->pos++;
	v->base = 16;
	if (v->mod == 1)
		print_num(v, (unsigned char)va_arg(ap, int));
	else if (v->mod == 2)
		print_num(v, (unsigned short int)va_arg(ap, int));
	else if (v->mod == 4)
		print_num(v, va_arg(ap, unsigned long int));
	else if (v->mod == 5)
		print_num(v, va_arg(ap, unsigned long long int));
	else if (v->mod == 6)
		print_num(v, va_arg(ap, uintmax_t));
	else if (v->mod == 8)
		print_num(v, va_arg(ap, size_t));
	else
		print_num(v, va_arg(ap, unsigned int));
	return (0);
}

int		ft_printf_o(va_list ap, t_elem *v)
{
	v->pos++;
	v->base = 8;
	if (v->mod == 1)
		print_num(v, (unsigned char)va_arg(ap, int));
	else if (v->mod == 2)
		print_num(v, (unsigned short int)va_arg(ap, int));
	else if (v->mod == 4)
		print_num(v, va_arg(ap, unsigned long int));
	else if (v->mod == 5)
		print_num(v, va_arg(ap, unsigned long long int));
	else if (v->mod == 6)
		print_num(v, va_arg(ap, uintmax_t));
	else if (v->mod == 8)
		print_num(v, va_arg(ap, size_t));
	else
		print_num(v, va_arg(ap, unsigned int));
	return (0);
}

int		ft_printf_u(va_list ap, t_elem *v)
{
	v->pos++;
	if (v->mod == 1)
		print_num(v, (unsigned char)va_arg(ap, int));
	else if (v->mod == 2)
		print_num(v, (unsigned short int)va_arg(ap, int));
	else if (v->mod == 4)
		print_num(v, va_arg(ap, unsigned long int));
	else if (v->mod == 5)
		print_num(v, va_arg(ap, unsigned long long int));
	else if (v->mod == 6)
		print_num(v, va_arg(ap, uintmax_t));
	else if (v->mod == 8)
		print_num(v, va_arg(ap, size_t));
	else
		print_num(v, va_arg(ap, unsigned int));
	return (0);
}

int		n(va_list ap, t_elem *v)
{
	v->pos++;
	if (v->mod == 1)
		*(va_arg(ap, signed char *)) = (signed char)(v->bpos + v->wn);
	else if (v->mod == 2)
		*(va_arg(ap, short *)) = (short)(v->bpos + v->wn);
	else if (v->mod == 4)
		*(va_arg(ap, long *)) = (long)(v->bpos + v->wn);
	else if (v->mod == 5)
		*(va_arg(ap, long long *)) = (long long)(v->bpos + v->wn);
	else if (v->mod == 6)
		*(va_arg(ap, intmax_t *)) = (intmax_t)(v->bpos + v->wn);
	else if (v->mod == 7)
		*(va_arg(ap, ptrdiff_t *)) = (ptrdiff_t)(v->bpos + v->wn);
	else
		*(va_arg(ap, int *)) = (int)(v->bpos + v->wn);
	return (0);
}
