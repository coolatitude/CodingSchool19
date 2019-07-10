/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv2rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 05:51:30 by pvanderl          #+#    #+#             */
/*   Updated: 2019/01/25 20:57:59 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function get_t_rgb
**
**	create a new t_rgb
**
**	@param:	color
**
**	out:	/
*/

t_rgb		get_t_rgb(int hex)
{
	t_rgb	c;

	c.hex = hex;
	c.r = (hex & R) >> 16;
	c.g = (hex & G) >> 8;
	c.b = (hex & B);
	return (c);
}

/*
**	function pixel_color
**
**	give the color of a point depending on the ratio position of a point on the
**	[if] segment
**
**	@param:	starting t_point of the segment
**	@param:	final t_point of the segment
**	@param:	ratio
**
**	@out:	/
*/

int			pixel_color(t_rgb i, t_rgb f, double di)
{
	int		r;
	int		g;
	int		b;

	r = (1.0 - di) * i.r + di * f.r;
	g = (1.0 - di) * i.g + di * f.g;
	b = (1.0 - di) * i.b + di * f.b;
	return (b + (g << 8) + (r << 16));
}

/*
**	function hsv2rgb
**
**	transform an hsv color and return it into a rgb int 0x00RRGGBB
**
**	@param:	the hue of a hsv color
**	@param:	the saturation of a hsv color
**	@param:	the value of a hsv color
**
**	@out:	the RGB integer
*/

int			hsv2rgb(double h, double s, double v)
{
	t_rgb	out;

	out.hh = (h > 360.0 ? 0.0 : h) / 60.0;
	out.i = (long)out.hh;
	out.ff = out.hh - out.i;
	out.p = v * (1.0 - s);
	out.q = v * (1.0 - (s * out.ff));
	out.t = v * (1.0 - (s * (1.0 - out.ff)));
	if (out.i == 0)
		return ((int)(255 * v) << 16 | (int)(out.t * 255) << 8 |
			(int)(out.p * 255));
		if (out.i == 1)
		return ((int)(255 * out.q) << 16 | (int)(255 * v) << 8 |
				(int)(255 * out.p));
		if (out.i == 2)
		return ((int)(255 * out.p) << 16 | (int)(255 * v) << 8 |
			(int)(out.t * 255));
		if (out.i == 3)
		return ((int)(255 * out.p) << 16 | (int)(255 * out.q) << 8 |
			(int)(255 * v));
		if (out.i == 4)
		return ((int)(255 * out.t) << 16 | (int)(255 * out.p) << 8 |
			(int)(255 * v));
		return ((int)(255 * v) << 16 |
			(int)(255 * out.p) << 8 | (int)(255 * out.q));
}
