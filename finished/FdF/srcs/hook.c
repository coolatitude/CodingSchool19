/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:17:08 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:07:47 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function keyboard_input
**
**	change the projection type or move the projection
**
**	@param:	the code of the keyboard input
**	@param:	a pointer on the data structure
**
**	@out:	/
*/

int		keyboard_input(int code, t_data *d)
{
	if (code == ESC_KEY)
	{
		destroy_data(d);
		exit(0);
	}
	else if (code == UP_KEY || code == DOWN_KEY)
		d->y0 = (code == UP_KEY) ? d->y0 - d->unit : d->y0 + d->unit;
	else if (code == RIGHT_KEY || code == LEFT_KEY)
		d->x0 = (code == RIGHT_KEY) ? d->x0 + d->unit : d->x0 - d->unit;
	else if (code == P_KEY)
		d->proj = &do_the_math_cav;
	else if (code == I_KEY)
		d->proj = &do_the_math_iso;
	else if (code == K2_KEY)
		d->proj = &do_the_math_2d;
	else if (code == NKMN_KEY)
		d->unit = (d->unit > 8) ? d->unit * 0.6 : d->unit;
	else if (code == NKPL_KEY)
		d->unit = (d->unit < 250) ? d->unit * 1.6 : d->unit;
	d->new_proj =
		(code == P_KEY || code == I_KEY || code == K2_KEY) ? 1 : 0;
	draw(d);
	return (1);
}

/*
**	funciton mouse
**
**	call actions depending on what we do: scroll, click in the circle,
**	in a colored square or somewhere else
**
**	@param:	the number of the button
**	@param:	the x coordinate
**	@param:	the Y coordinate
**	@param:	a pointer on the data structure
**
**	@out:	1
*/

int		mouse(int button, int x, int y, t_data *d)
{
	if (button == 1)
	{
		button = (y > d->cy && y < d->cy + 20) ? 1 : 0;
		if (button && x > d->cx && x < d->cx + 20)
			d->selected = 1;
		else if (button && x > d->cx + 130 && x < d->cx + 150)
			d->selected = 2;
		else if (button && x > d->cx + 260 && x < d->cx + 280)
			d->selected = 3;
		else if ((y - 1000) * (y - 1000) + (x - 250) * (x - 250) < RAY * RAY &&
				d->selected)
			d->cz[d->selected - 1] =
				get_color_range(d, x - 250 + RAY, y - 1000 + RAY);
		else
			d->selected = 0;
		draw_colors(d);
		if (d->selected)
			draw(d);
	}
	else if (button == 4 || button == 5)
	{
		d->zcst += (button == 4 ? 2.5 : -2.5);
		draw(d);
	}
	return (1);
}
