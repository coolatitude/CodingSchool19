/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:32:41 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/23 01:18:53 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

/*
**	mod:	0 rien
**			1 hh
**			2 h
**			3 L
**			4 l
**			5 ll
**			6 j
**			7 t
**			8 z
*/

typedef struct		s_elem
{
	char	*cs;
	char	*nbuf;
	char	*np;
	int		altfmt;
	int		base;
	int		cap;
	char	sign_char;
	int		length;
	int		ladjust;
	int		t;
	int		padc;
	int		plus_sign;
	int		prec;
	char	*buff;
	int		bpos;
	int		wn;
	int		wg;
	int		pos;
	int		mod;
	char	*pref;
}					t_elem;

#endif
