/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:13:38 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:00:36 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function do_the_math_2d
**
**	calculate the image x and the image y of a point
**	for the two dimension projection
**
**	@param:	a pointer to the data structure
**	@param:	the x coordinate
**	@param:	the y coordinate
**	@param: the z coordinate
**
**	out:	/
*/

void	do_the_math_2d(t_data *d, int x, int y, int z)
{
	z = 0;
	d->map[y][x].ix = d->x0 + x * d->unit;
	d->map[y][x].iy = d->y0 + y * d->unit;
}

/*
**	function do_the_math_cav
**
**	calculate the image x and the image y of a point
**	for the paralel projection
**
**	@param:	a pointer to the data structure
**	@param:	the x coordinate
**	@param:	the y coordinate
**	@param: the z coordinate
**
**	out:	/
*/

void	do_the_math_cav(t_data *d, int x, int y, int z)
{
	d->map[y][x].ix = d->x0 + x * d->unit + d->zcst * z;
	d->map[y][x].iy = d->y0 + y * d->unit + d->zcst * z / 2;
}

/*
**	function do_the_math_iso
**
**	calculate the image x and the image y of a point
**	for the isometric projection
**
**	@param:	a pointer to the data structure
**	@param:	the x coordinate
**	@param:	the y coordinate
**	@param: the z coordinate
**
**	out:	/
*/

void	do_the_math_iso(t_data *d, int x, int y, int z)
{
	d->map[y][x].ix = d->x0 +
		d->unit * (d->iso_cst1 * x - d->iso_cst2 * y);
	d->map[y][x].iy =
		d->y0 + -z * d->zcst + d->unit *
		((d->iso_cst1 * x + d->iso_cst2 * y) / 2);
}

/*
**	function adjust_to_page
**
**	calculate the unit size and the x0 depending on the map size
**
**	@param:	a pointer to the data structure
**
**	out:	/
*/

void	ajust_to_page(t_data *d)
{
	d->new_proj = 0;
	d->x0 = 350;
	d->y0 = 200;
	d->zcst = 5;
	if (*(d->proj) == do_the_math_2d || *(d->proj) == do_the_math_cav)
	{
		d->unit = 1100 / d->len;
		d->unit = (d->unit < (800 / d->high) ? d->unit : (800 / d->high));
		if (d->unit < 5)
			d->unit = 5;
	}
	else if (*(d->proj) == do_the_math_iso)
	{
		d->y0 = d->y0 + d->map[0][0].z;
		d->unit = 1100 / ((d->iso_cst1 * d->len) + (d->iso_cst2 * d->high));
		d->unit = (d->unit < 5 ? 5 : d->unit);
		d->x0 = d->x0 + d->unit * d->iso_cst2 * d->high;
	}
}

/*
**	function do_the_math
**
**	reposition the projection if necessary and call do the math for each point
**
**	@param:	a pointer on the data structure
**
**	@out:	/
*/

void	do_the_math(t_data *d)
{
	int	y;
	int	x;

	if (d->new_proj)
		ajust_to_page(d);
	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (x < d->len)
		{
			d->proj(d, x, y, d->map[y][x].z);
			x++;
		}
		y++;
	}
}
