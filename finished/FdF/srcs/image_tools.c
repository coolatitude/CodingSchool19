/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:58:32 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:10:31 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function add_tools
**
**	add the tools at the left of the window
**
**	@param:	a pointer on the data structure
**
**	@out:	/
*/

void			add_tools(t_data *d)
{
	int	i;

	mlx_string_put(d->init, d->window, 135, 10, R, "F I L    D E    F E R");
	mlx_string_put(d->init, d->window, 30, 60, WHITE, "Commands :");
	mlx_string_put(d->init, d->window, 65, 90, WHITE, "Press 2 for 2D");
	mlx_string_put(d->init, d->window, 65, 110, WHITE, "Press P for paralel");
	mlx_string_put(d->init, d->window, 65, 130, WHITE, "Press I for isometric");
	mlx_string_put(d->init, d->window, 65, 170, WHITE,
			"Scroll to increase or decrease depth");
	mlx_string_put(d->init, d->window, 65, 190, WHITE,
			"Use arrows to move the image");
	mlx_string_put(d->init, d->window, 65, 210, WHITE,
			"Press + or - to zoom");
	i = -1;
	while (++i < 500)
		mlx_pixel_put(d->init, d->window, i, 40, R);
	i = -1;
	while (++i < 1200)
		mlx_pixel_put(d->init, d->window, 499, i, R);
	draw_range(d, 250, 1000);
	draw_colors(d);
}
