/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgauthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:06:34 by rgauthie          #+#    #+#             */
/*   Updated: 2019/02/01 12:34:48 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	function get_title
**
**	get the title of the window
**
**	@param: the path of the file to read
**
**	@out:	the title
*/

static char		*get_title(char *s)
{
	char **tmp;

	tmp = ft_strsplit(s, '/');
	s = ft_strjoin("FDF : ", tmp[tablelen(tmp) - 1]);
	char_table_free(tmp);
	return (s);
}

/*
**	function init_data
**
**	create a t_data element
**
**	@param:	/
**
**	@out:	the t_data
*/

t_data			init_data(void)
{
	t_data	d;

	d.zcst = 5;
	d.iso_cst1 = 0.5;
	d.iso_cst2 = 0.5;
	d.proj = &do_the_math_cav;
	d.new_proj = 1;
	d.cx = 108;
	d.cy = 870;
	d.point_z_min = -1;
	d.point_z_max = 1;
	d.selectedc = -1;
	d.cz[0] = 0x603906;
	d.cz[1] = 0x156601;
	d.cz[2] = 0xffee05;
	d.img_ptr = NULL;
	return (d);
}

/*
**	function main
**
**	open the file and get the inputs
**
**	@param:	the arguments count
**	@param:	the arguments table
**
**	@out:	0 if all functionned correctly
*/

int				main(int argc, char *argv[])
{
	int		fd;
	t_data	data;
	int		out;
	char	*s;

	data = init_data();
	out = 0;
	if (argc != 2)
		write(0, USAGE, USAGE_LEN);
	else if (!(fd = open(argv[1], O_RDONLY)))
		return (0);
	else
	{
		read_input(fd, &data);
		if ((data.map))
		{
			s = get_title(argv[1]);
			out = startlib(&data, s);
			free(s);
		}
		close(fd);
	}
	return (out);
}
