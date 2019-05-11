/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagetools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 06:14:16 by pvanderl          #+#    #+#             */
/*   Updated: 2019/01/28 14:52:49 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function set_color
**
**	set the color color at the position (x,y) in the img image
**
**	@param:	a pointer on the data structure
**	@param:	the x coordinate
**	@param:	the y coordinate
**	@param:	the color as integer
**
**	@out:	/
*/

void	set_color(t_data *d, int x, int y, int color)
{
	ft_memcpy(d->img + (d->iw * y + (d->img_def / 8) * x), &color, 3);
}
