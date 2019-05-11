/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:12:15 by pvanderl          #+#    #+#             */
/*   Updated: 2019/01/28 14:57:25 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function type1
**
**	draw a line if delta x > delta y
**
**	@param:	startint t_point of the line
**	@param:	ending t_point of the line
**	@param:	t_data to write the image
**
**	out:	/
*/

static void		type1(t_point p1, t_point p2, t_data *d)
{
	int		x;
	int		y;
	float	den;

	x = p1.ix;
	while (x <= p2.ix)
	{
		den = p2.ix - p1.ix;
		if (den != 0.0)
		{
			y = p1.iy + ((p2.iy - p1.iy) * (x - p1.ix) / (p2.ix - p1.ix));
			if (x >= 0 && y >= 0 && x < 1500 && y < 1200)
				set_color(d, x, y,
						pixel_color(p1.c, p2.c,
							fabs((float)(x - p1.ix) / (p2.ix - p1.ix))));
		}
		x++;
	}
}

/*
**	function type2
**
**	draw a line if delta y > delta x
**
**	@param:	startint t_point of the line
**	@param:	ending t_point of the line
**	@param:	t_data to write the image
**
**	out:	/
*/

static void		type2(t_point p1, t_point p2, t_data *d)
{
	int		x;
	int		y;
	float	den;

	y = p1.iy;
	while (y <= p2.iy)
	{
		den = (p2.iy - p1.iy);
		if (den != 0.0)
		{
			x = p1.ix + ((p2.ix - p1.ix) * (y - p1.iy) / (p2.iy - p1.iy));
			if (x >= 0 && y >= 0 && x < 1500 && y < 1200)
				set_color(d, x, y,
						pixel_color(p1.c, p2.c,
							fabs((float)(y - p1.iy) / (p2.iy - p1.iy))));
		}
		y++;
	}
}

/*
**	function draw_line
**
**	redirect to the right type depending on the two points
**
**	@param: starting point structure
**	@param:	ending point structure
**
**	@out:	/
*/

void			draw_line(t_point p1, t_point p2, t_data *d)
{
	int dx;
	int dy;

	dx = p2.ix - p1.ix;
	dy = p2.iy - p1.iy;
	if (dx > 0 && dy > 0)
		(dx > dy) ? type1(p1, p2, d) : type2(p1, p2, d);
	else if (dx < 0 && dy < 0)
		(dx > dy) ? type2(p2, p1, d) : type1(p2, p1, d);
	else if (dx < 0 && dy > 0)
		(-(dx) > dy) ? type1(p2, p1, d) : type2(p1, p2, d);
	else if (dx > 0 && dy < 0)
		(dx < -(dy)) ? type2(p2, p1, d) : type1(p1, p2, d);
	else if (dx > 0 && dy == 0)
		type1(p1, p2, d);
	else if (dx < 0 && dy == 0)
		type1(p2, p1, d);
	else if (dy < 0 && dx == 0)
		type2(p2, p1, d);
	else if (dy > 0 && dx == 0)
		type2(p1, p2, d);
}
