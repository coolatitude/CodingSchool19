/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:11:17 by pvanderl          #+#    #+#             */
/*   Updated: 2018/12/17 15:51:07 by jhuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	function isfitting
**
**	Check if a given tetromino fit in the grid in a given i and j.
**
**	@param: chainlist with the actual tetromino to check
**	@param: the grid
**	@param: the i begin position where the tetro should be put
**	@param: the j begin position where the tetro should be put
*/

int		isfitting(t_tetro *elem, char **grid, int i, int j)
{
	int		k;
	int		l;
	int		res;

	res = 1;
	k = 0;
	while ((res == 1) && (k < elem->last_i - elem->first_i + 1))
	{
		l = 0;
		while ((res == 1) && (l < elem->last_j - elem->first_j + 1))
		{
			if ((grid[i + k][j + l] != EM) &&
					(elem->piece[k + elem->first_i][l + elem->first_j] == BL))
				res = 0;
			l = l + 1;
		}
		k = k + 1;
	}
	return (res);
}

/*
**	function put_tetro
**
**	Put a tetromino with a certain letter in the grid in a given position.
**
**	@param: chainlist with the actual tetromino to remove
**	@param: the grid
**	@param: the array i which contains the i and j position where the tetro
**			has to be put.
**	@param: the letter used to put the tetromino in the grid.
*/

void	put_tetro(t_tetro *elem, char **grid, int *i, char c)
{
	int		k;
	int		l;

	k = 0;
	while (k < elem->last_i - elem->first_i + 1)
	{
		l = 0;
		while (l < elem->last_j - elem->first_j + 1)
		{
			if (elem->piece[k + elem->first_i][l + elem->first_j] == BL)
				grid[i[0] + k][i[1] + l] = c;
			l = l + 1;
		}
		k = k + 1;
	}
}

/*
**	function remove_tetro
**
**	Remove a tetromino from the grid in a given position.
**
**	@param: chainlist with the actual tetromino to remove
**	@param: the grid
**	@param: the i position where the removal of the tetro begins
**	@param: the j position where the removal of the tetro begins
*/

void	remove_tetro(t_tetro *elem, char **grid, int i, int j)
{
	int		k;
	int		l;

	k = 0;
	while (k < elem->last_i - elem->first_i + 1)
	{
		l = 0;
		while (l < elem->last_j - elem->first_j + 1)
		{
			if (elem->piece[k + elem->first_i][l + elem->first_j] == BL)
				grid[i + k][j + l] = EM;
			l = l + 1;
		}
		k = k + 1;
	}
}

/*
**	function backtracking
**
**	Try all the combinations possible of tetrominos positioning in the grid
**	with a bruteforce backtracking method.
**
**	@param: chainlist containing all the tetrominos
**	@param: the length of our len*len matrix
**	@param: the grid
**	@param: the letter to fill our grid with.
**
**	@out: returns 1 if the littlest square has been found and prints it,
**        else returns 0
*/

int		backtracking(t_tetro *elem, int len, char **grid, char c)
{
	int		i[2];
	int		res;

	res = 0;
	if (elem != NULL)
	{
		i[0] = 0;
		while ((res == 0) && (i[0] + elem->last_i - elem->first_i + 1 <= len))
		{
			i[1] = 0;
			while ((res == 0) &&
					(i[1] + elem->last_j - elem->first_j + 1 <= len))
			{
				if (isfitting(elem, grid, i[0], i[1]))
				{
					put_tetro(elem, grid, i, c);
					res = backtracking(elem->next, len, grid, c + 1);
					remove_tetro(elem, grid, i[0], i[1]);
				}
				i[1]++;
			}
			i[0]++;
		}
	}
	return ((elem) ? res : print_grid(grid, len));
}

/*
**	function resolve
**
**	Function creating blank grid(s) that will be used by the
**	backtracking function in order to resolve the littlest square
**	possible with all the tetrominos received.
**
**	@param: chainlist containing all the tetrominos
**
**	@out: /
*/

void	resolve(t_tetro *elem)
{
	int		n;
	int		len;
	t_tetro	*temp;
	char	**grid;

	temp = elem;
	n = 0;
	while (temp != NULL)
	{
		n = n + 4;
		temp = temp->next;
	}
	len = 2;
	while (len * len < n)
		len = len + 1;
	grid = blank_grid(len);
	while (grid && backtracking(elem, len, grid, 'A') == 0)
	{
		free_table(&grid);
		len++;
		grid = blank_grid(len);
	}
	free_table(&grid);
}
