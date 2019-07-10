/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:23:43 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:32:42 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function destroy_data
**
**	destroy the content of a t_data element
**
**	@param:	a pointer on a t_data element
**
**	@out:	/
*/

void	destroy_data(t_data *d)
{
	point_table_free(d->map);
	mlx_destroy_image(d->init, d->range_ptr);
	mlx_destroy_window(d->init, d->window);
}

/*
**	function point_table_free
**
**	free a 2 dimension table of t_point
**
**	@param:	the t_point table to free
**
**	@out:	NULL
*/

t_point	**point_table_free(t_point **table)
{
	int i;

	if (table)
	{
		i = 0;
		while (table[i])
			free(table[i++]);
		free(table);
	}
	return (NULL);
}

/*
**	function tablelen
**
**	get the length of a table
**
**	@param:	a table of char *
**
**	@out:	the length of the table
*/

int		tablelen(char **t)
{
	int i;

	i = 0;
	while (t && t[i])
		i++;
	return (i);
}

/*
**	function ft_getnbr
**
**	get an number from a string
**
**	@param:	a string containing the number
**
**	@out:	the number;
*/

int		ft_getnbr(char *s)
{
	int out;
	int	sign;

	out = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (ft_isdigit(*s))
	{
		out = out * 10 + (*s - '0');
		s++;
	}
	return (sign * out);
}

/*
**	function char_table_free
**
**	free a table of char *
**
**	@param:	a table to free
**
**	@out:	NULL
*/

char	**char_table_free(char **table)
{
	int i;

	if (table)
	{
		i = 0;
		while (table[i])
		{
			free(table[i]);
			i++;
		}
		free(table);
	}
	return (NULL);
}
