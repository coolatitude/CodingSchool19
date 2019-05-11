/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:32:41 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/26 17:18:11 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_struct.h"
# include <stdarg.h>
# include "libft.h"
# include <stddef.h>
# include <limits.h>
# define BUFF_SIZE 38
# define MAXBUF 256
# define TRUE 1
# define FALSE 0
# define CAP 16

void	print_num(t_elem *v, unsigned long long u);
int		n(va_list ap, t_elem *v);

/*
**	parsing
*/

int		parse(char *s, t_elem *v, va_list ap);
int		string_buff_n(char *s, int nb, t_elem *v);
int		string_to_buff(char *s, t_elem *v);
void	putchar_buff(char c, t_elem *v);
void	putcharn(char c, int nb, t_elem *v);

/*
**	tools0
*/

int		ft_putstrn(char *s, int max);
int		ft_putcharn(char c, int nb);
size_t	nbr_base_length(int n, int base);
size_t	unbr_base_length(unsigned int n, unsigned int base);
char	*ft_itoa_base(char *s, int nb, int base);

/*
**	ft_set_lh_flag
**	8 functions
*/

void	ft_getbigl(t_elem *v);
void	ft_getl(t_elem *v);
void	ft_getll(t_elem *v);
void	ft_geth(t_elem *v);
void	ft_gethh(t_elem *v);
void	ft_gett(t_elem *v);
void	ft_getz(t_elem *v);
void	ft_getj(t_elem *v);

/*
**	tools
*/

int		ft_printf_d(va_list ap, t_elem *v);
int		ft_printf_o(va_list ap, t_elem *v);
int		ft_printf_u(va_list ap, t_elem *v);
int		ft_printf_x(va_list ap, t_elem *v);

/*
**	ft_printf
*/

int		p(void *p, t_elem *v);
int		d(long long int nb, t_elem *v);
int		u(unsigned long long int nb, t_elem *v);
int		fs(char *s, t_elem *v);
int		ft_printf_percent(t_elem *v);
int		fc(int c, t_elem *v);

/*
**	ft_printf_f
*/

int		ft_printf_f(double nb, t_elem *v);

/*
**	ft_printf
*/

int		ft_printf(const char *format, ...);

/*
**	getters0
**	5 functions
*/

void	get_fwidth(char *s, t_elem *v, va_list ap);
void	get_dot(char *s, t_elem *v, va_list ap);
void	get_minus(t_elem *v);
void	get_plus(t_elem *v);
void	get_space(t_elem *v);

/*
**	getters1
**	2 functions
*/

void	get_zero(t_elem *v);
void	get_sharp(t_elem *v);

#endif
