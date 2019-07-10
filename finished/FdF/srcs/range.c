/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:10:56 by pvanderl          #+#    #+#             */
/*   Updated: 2019/01/25 21:38:27 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function draw_range
**
**	generate an image and draw the circle on it and push it on the window
**
**	@param:	a pointer on the data structure
**	@param:	the x position of the center of the range circle
**	@param:	the y position of the center of the range circle
**
**	@out:	/
*/

void	draw_range(t_data *d, int x, int y)
{
	double	ray;
	double	i;
	double	ratio;
	double	angle;

	d->range_ptr = mlx_new_image(d->init, 2 * RAY, 2 * RAY);
	d->range = mlx_get_data_addr(
			d->range_ptr, &(d->img_def), &(d->rw), &(d->endian));
	ray = RAY;
	i = 0;
	while (ray > 0)
	{
		ratio = ray / RAY;
		angle = -0.5;
		while ((angle += 0.5) < 360.0)
			set_color_range(d, RAY + ray * cos(PI * angle / 180),
					RAY + ray * sin(PI * angle / 180),
					mlx_get_color_value(d->init, hsv2rgb(angle, 1, ratio)));
		ray -= 1.0;
	}
	mlx_put_image_to_window(d->init, d->window, d->range_ptr, x - RAY, y - RAY);
}

/*
**	function get_color_range
**
**	return the color of a pixel in the range image
**
**	@param:	a pointer on the data_structure
**	@param:	the x coordinate
**	@param: the y coordinate
**
**	@out:	the color;
*/

int		get_color_range(t_data *d, int x, int y)
{
	int		out;

	ft_memcpy(&out, d->range + pix_pos_range(d, x, y), 3);
	return (out);
}

/*
**	funciton set_color_range
**
**	set a pixel of the image range to a specific color
**
**	@param:	a pointer on the data structure
**	@param: the x position
**	@param:	the y position
**	@param:	the color as an int
**
**	@out:	/
*/

void	set_color_range(t_data *d, double x, double y, int color)
{
	ft_memcpy(d->range + pix_pos_range(d, x, y), &color, 3);
}

/*
**	function pix_pos_range
**
**	get the position in the char *range depending on the position x, y
**	in the image
**
**	@param:	a pointer on the data structure
**	@param:	the x position
**	@param:	the y position
**
**	@out:	the position from the *range
*/

int		pix_pos_range(t_data *d, int x, int y)
{
	return (d->rw * y + (d->img_def / 8) * x);
}
