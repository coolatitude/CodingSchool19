/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:44:46 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:33:50 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function new_t_point
**
**	create a new t_point and get the minimum and maximum z
**
**	@param:	a pointer on the data structure
**	@param:	the x coordinate
**	@param:	the y coordinate
**	@param:	the z coordinate
**
**	@param:	the new t_point
*/

static t_point	new_t_point(t_data *d, int x, int y, int z)
{
	t_point		p;

	if (z < 0 && z < d->point_z_min)
		d->point_z_min = z;
	else if (z > 0 && z > d->point_z_max)
		d->point_z_max = z;
	p.z = z;
	p.x = x;
	p.y = y;
	return (p);
}

/*
**	function line_to_t_point_table
**
**	transform a line and generate a new table of size + 1
**
**	@param:	a pointer on the data structure
**	@param:	the char ** of numbers
**
**	@out:	/
*/

static void		line_to_t_point_table(t_data *d, char **tmp)
{
	int			i;
	t_point		**out;

	d->high = 1 + tablelen((char **)d->map);
	i = -1;
	if (!(out = (t_point **)malloc(sizeof(t_point *) * (d->high + 1))) ||
			!(out[d->high - 1] = (t_point *)malloc(sizeof(t_point) * (d->len))))
	{
		point_table_free(d->map);
		return ;
	}
	while (d->high > 1 && ++i < d->high - 1)
	{
		out[i] = d->map[i];
		d->map[i] = NULL;
	}
	if (d->high > 1)
		point_table_free(d->map);
	i = -1;
	while (tmp[++i])
		out[d->high - 1][i] = new_t_point(d, i, d->high - 1, ft_getnbr(tmp[i]));
	out[d->high] = NULL;
	d->map = out;
}

/*
**	function read_input
**
**	generate a table of t_point from the input
**
**	@param:	the file descriptor
**	@param:	a pointer on the data structure
**
**	@out:	/
*/

void			read_input(int fd, t_data *data)
{
	char	*line;
	int		rtn;
	char	**tmp;

	data->map = NULL;
	while ((rtn = get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) && (tmp = ft_strsplit(line, ' ')))
		{
			data->len = tablelen(tmp);
			line_to_t_point_table(data, tmp);
			char_table_free(tmp);
		}
		else
			data->map = point_table_free(data->map);
		free(line);
		if (!data->map)
			break ;
	}
	if (rtn < 0)
		data->map = point_table_free(data->map);
}
