/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:05:46 by rgauthie          #+#    #+#             */
/*   Updated: 2019/02/01 11:59:49 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define USAGE "usage: ./fdf map_file\n"
# define USAGE_LEN 22
# define R_XPM "./../img/rgauthie.XPM"
# define P_XPM "../img/pvanderl.XPM"
# define R 0x00ff0000
# define G 0x0000ff00
# define B 0x000000ff
# define WHITE 0x00ffffff
# define PI 3.14159265359
# define RAY 60.0
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include "keycode.h"
# include "mlx.h"
# include "structs.h"

/*
**	from tools
**	5 functions
*/

int				ft_getnbr(char *s);
int				tablelen(char **t);
t_point			**point_table_free(t_point **table);
char			**char_table_free(char **table);
void			destroy_data(t_data *d);

/*
**	from input
**	3 functions
*/

void			read_input(int fd, t_data *data);

/*
**	from window
**	2 functions
*/

int				startlib(t_data *data, char *s);

/*
**	from hook
**	2 functions
*/

int				keyboard_input(int code, t_data *data);
int				mouse(int button, int x, int y, t_data *data);

/*
**	from draw
**	3 functions
*/

int				draw(t_data *data);

/*
**	from drawlines
**	3 functions
*/

void			draw_line(t_point p1, t_point p2, t_data *d);

/*
**	from imagetools
**	1 function
*/

void			set_color(t_data *d, int x, int y, int color);

/*
**	from calculs
**	5 functions
*/

void			do_the_math_cav(t_data *d, int x, int y, int z);
void			do_the_math_iso(t_data *d, int x, int y, int z);
void			do_the_math_2d(t_data *d, int x, int y, int z);
void			do_the_math(t_data *d);

/*
**	from hsv_rgb
**	3 functions
*/

t_rgb			get_t_rgb(int hex);
int				pixel_color(t_rgb i, t_rgb f, double di);
int				hsv2rgb(double h, double s, double v);

/*
**	from image_tools
**	1 function
*/

void			add_tools(t_data *d);

/*
**	from range
**	4 functions
*/

void			draw_range(t_data *d, int x, int y);
int				pix_pos_range(t_data *d, int x, int y);
int				get_color_range(t_data *d, int x, int y);
void			set_color_range(t_data *d, double x, double y, int color);

/*
**	from draw_colors
**	2 functions
*/

void			draw_colors(t_data *d);

#endif
