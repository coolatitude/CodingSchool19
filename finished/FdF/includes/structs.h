/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:55:07 by pvanderl          #+#    #+#             */
/*   Updated: 2019/01/25 21:57:31 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
	int		hex;
	double	hh;
	double	p;
	double	q;
	double	t;
	double	ff;
	long	i;
}				t_rgb;

typedef struct	s_hsv
{
	double h;
	double s;
	double v;
}				t_hsv;

typedef struct	s_point
{
	int		ix;
	int		iy;
	int		z;
	int		x;
	int		y;

	t_rgb	c;
}				t_point;

typedef	struct	s_data
{
	t_point		**map;
	int			len;
	int			high;

	void		*window;
	void		*init;

	int			endian;
	int			img_def;
	char		*img;
	void		*img_ptr;
	char		*range;
	void		*range_ptr;
	char		*colors;
	void		*colors_ptr;
	int			cw;
	int			cx;
	int			cy;
	int			selectedc;
	int			rw;
	int			iw;
	int			ih;

	int			point_z_min;
	int			point_z_max;
	int			selected;
	int			cz[3];

	void		(*proj)(struct s_data *, int, int, int);
	int			new_proj;
	int			unit;
	float		zcst;
	float		iso_cst1;
	float		iso_cst2;
	int			x0;
	int			y0;
}				t_data;

#endif
