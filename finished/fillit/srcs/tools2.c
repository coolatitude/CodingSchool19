/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:09:36 by pvanderl          #+#    #+#             */
/*   Updated: 2018/12/17 14:09:43 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	function print_grid
**
**	print the found grid onto the screen
**
**	@param:	the grid (2D char table) to print
**	@param:	the length of the grid
**
**	@out:	1
*/

int		print_grid(char **grid, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}

/*
**	function blank_grid
**
**	generate a grid with EM chars
**
**	@param:	the size of the grid
**
**	@out:	the grid or null if malloc failled
*/

char	**blank_grid(int len)
{
	char	**grid;
	int		i;
	int		j;

	if (!(grid = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * len)))
			return ((free_table(&grid)) ? NULL : NULL);
		j = -1;
		while (++j < len)
			grid[i][j] = EM;
	}
	grid[i] = NULL;
	return (grid);
}
