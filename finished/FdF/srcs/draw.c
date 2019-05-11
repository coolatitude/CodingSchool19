/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 00:05:58 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:07:55 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function add_point
**
**	set the color of eache point on the graph
**
**	@param:	a pointer on the data structure
**
**	@out:	/
*/

static void		add_point(t_data *d)
{
	int		x;
	int		y;
	int		color;
	t_rgb	c[3];

	c[0] = get_t_rgb(d->cz[0]);
	c[1] = get_t_rgb(d->cz[1]);
	c[2] = get_t_rgb(d->cz[2]);
	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (x < d->len)
		{
			color = (d->map[y][x]).z < 0 ?
				pixel_color(c[0], c[1],
					(float)(d->map[y][x].z - d->point_z_min) / d->point_z_min) :
				pixel_color(c[1], c[2],
					(float)(d->map[y][x].z) / d->point_z_max);
			d->map[y][x].c = get_t_rgb(color);
			x++;
		}
		y++;
	}
}

/*
**	function draw_lines
**
**	call draw line for each segment of the graph
**
**	@param:	a pointer on the data structure
**
**	@out:	/
*/

static void		draw_lines(t_data *d)
{
	int		x;
	int		y;

	if (d->high == d->len && d->len == 1)
	{
		d->unit = 5;
		x = d->map[0][0].ix;
		y = d->map[0][0].iy;
		if (x >= 0 && y >= 0 && x < 1500 && y < 1200)
			set_color(d, x, y, d->map[0][0].c.hex);
	}
	y = 0;
	while (y < d->high)
	{
		x = 0;
		while (x < d->len)
		{
			if (x != d->len - 1)
				draw_line(d->map[y][x], d->map[y][x + 1], d);
			if (y != d->high - 1)
				draw_line(d->map[y][x], d->map[y + 1][x], d);
			x++;
		}
		y++;
	}
}

/*
**	function draw
**
**	function called on each changement
**
**	@param:	a pointer on the data structure
**
**	@out:	1
*/

int				draw(t_data *d)
{
	do_the_math(d);
	d->img_ptr = mlx_new_image(d->init, 1500, 1200);
	d->img = mlx_get_data_addr(d->img_ptr, &(d->img_def),
			&(d->iw), &(d->endian));
	add_point(d);
	draw_lines(d);
	mlx_put_image_to_window(d->init, d->window, d->img_ptr, 500, 0);
	mlx_destroy_image(d->init, d->img_ptr);
	return (1);
}
