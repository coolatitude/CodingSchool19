/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:01:12 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/01 12:20:11 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function custom_exit
**
**	exit on red cross press
*/

static int		custom_exit(int key, t_data *d)
{
	exit(0);
	point_table_free(d->map);
	free(d);
	return (key);
}

/*
**	function startlib
**
**	start the window and launch the drawer
**
**	@param:	a pointer on the data structure
**	@param:	the name of the window
**
**	@out:	an int
*/

int				startlib(t_data *d, char *s)
{
	d->init = mlx_init();
	d->window = mlx_new_window(d->init, 2000, 1200, s);
	add_tools(d);
	mlx_mouse_hook(d->window, mouse, d);
	mlx_expose_hook(d->window, draw, d);
	mlx_key_hook(d->window, keyboard_input, d);
	mlx_hook(d->window, 17, 1L << 17, custom_exit, d);
	mlx_loop(d->init);
	return (0);
}
