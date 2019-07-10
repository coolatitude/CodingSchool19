/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:32:59 by pvanderl          #+#    #+#             */
/*   Updated: 2018/12/17 15:44:36 by jhuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetro	*elem;

	if (argc != 2)
		ft_putendl("usage: ./fillit file");
	else
	{
		elem = check_and_save_content(open(argv[1], O_RDONLY));
		if (elem != NULL)
		{
			resolve(elem);
			elem = custom_free(elem);
		}
		else
			ft_putendl("error");
	}
	return (0);
}
