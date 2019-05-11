/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:54:58 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:10:51 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function add_square
**
**	add the white square around the selected color
**
**	@param:	pointer on the data structure
**	@param:	color as an int
**
**	@out:	/
*/

static void		add_square(t_data *d, int c)
{
	int i;
	int k;
	int h;

	h = (d->img_def / 8);
	k = d->selected - 1;
	i = -1;
	while (++i < 22)
	{
		ft_memcpy(d->colors + 0 + (d->img_def / 8) * (i + 130 * k), &c, 3);
		ft_memcpy(d->colors + d->cw * 1 + h * (i + 130 * k), &c, 3);
		ft_memcpy(d->colors + d->cw * 22 + h * (i + 130 * k), &c, 3);
		ft_memcpy(d->colors + d->cw * 23 + h * (i + 130 * k), &c, 3);
		ft_memcpy(d->colors + d->cw * i + h * (0 + 130 * k), &c, 3);
		ft_memcpy(d->colors + d->cw * i + h * (1 + 130 * k), &c, 3);
		ft_memcpy(d->colors + d->cw * i + h * (20 + 130 * k), &c, 3);
		ft_memcpy(d->colors + d->cw * i + h * (21 + 130 * k), &c, 3);
	}
}

/*
**	function draw_colors
**
**	create an image with the three color square and add it on the window
**
**	@param:	a pointer on the data structure
**
**	@out:	/
*/

void			draw_colors(t_data *d)
{
	int	i;
	int	j;
	int	k;

	d->colors_ptr = mlx_new_image(d->init, 286, 24);
	d->colors = mlx_get_data_addr(
			d->colors_ptr, &(d->img_def), &(d->cw), &(d->endian));
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 20)
		{
			k = -1;
			while (++k < 20)
				ft_memcpy(d->colors + d->cw * (2 + j) +
						(d->img_def / 8) * (2 + 130 * i + k), &(d->cz[i]), 3);
		}
	}
	if (d->selected)
		add_square(d, WHITE);
	mlx_put_image_to_window(d->init, d->window, d->colors_ptr, d->cx, d->cy);
	mlx_destroy_image(d->init, d->colors_ptr);
}
