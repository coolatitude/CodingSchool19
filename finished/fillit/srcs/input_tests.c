/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:21:14 by pvanderl          #+#    #+#             */
/*   Updated: 2018/12/18 15:41:56 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	function sub_check_form
**
**	subfunction from check_form
*/

void		sub_check_form(char **s, int *i)
{
	if (s[i[0]][i[1]] == BL)
	{
		i[2]++;
		if ((i[1] + 1 != 4) && (s[i[0]][i[1] + 1] == BL))
			i[3]++;
		if ((i[0] + 1 != 4) && (s[i[0] + 1][i[1]] == BL))
			i[3]++;
	}
	else if (s[i[0]][i[1]] != EM)
		i[4] = 0;
}

/*
**	function check_form
**
**	int *i:	i[0] = i
**			i[1] = j
**			i[2] = number of blocks
**			i[3] = number of links
**			i[4] = res
**
**	If the form of the given parameter is correct.
**	The function checks the form by verifying that s is
**	a matrix of 4x4 (NULL and '\0' not included), contains exactly 4 '#',
**	and that s has at least 3 links between blocks.
**
**	@param: 4*4 char matrix containing the tetromino
**
**	@out: returns 1 if the form is correct, else returns 0
*/

int			check_form(char **s)
{
	int		i[5];

	i[4] = 1;
	i[2] = 0;
	i[0] = -1;
	i[3] = 0;
	while ((i[4] != 0) && (++i[0] < 4))
	{
		i[1] = -1;
		if ((i[0] + 1 < 4) && ((s[i[0] + 1] == NULL) ||
					(ft_strlen(s[i[0] + 1]) != 4)))
			i[4] = 0;
		while ((i[4] != 0) && (s[i[0]][++i[1]] != '\0'))
			sub_check_form(s, i);
		if (i[1] != 4)
			i[4] = 0;
	}
	return (((i[0] != 4) || (i[2] != 4) || (i[3] < 3)) ? 0 : i[4]);
}

/*
**	function addtet
**
**	Creates a new t_tetro struct, with the locations of the
**	the tetromino in the table s, and adds it to the end of the tet
**	chainlist.
**
**	@param: a pointer to the first tetro of the list
**	@param: 4*4 char matrix containing the tetromino
**
**	@out: /
*/

void		addtet(t_tetro **tet, char **s)
{
	t_tetro		*new;
	int			i;
	int			j;

	new = t_tetro_new(s);
	i = -1;
	while (s[++i] != NULL)
	{
		j = -1;
		while (s[i][++j] != '\0')
		{
			if (s[i][j] == BL)
			{
				if ((new->first_j == -1) || (j < new->first_j))
					new->first_j = j;
				if (j > new->last_j)
					new->last_j = j;
				if (new->first_i == -1)
					new->first_i = i;
				if (i > new->last_i)
					new->last_i = i;
			}
		}
	}
	t_tetro_add(tet, new);
}

/*
**	function check_and_save_content
**
**	Function that reads in a file descriptor, retrieves the tetromino,
**	check if the format of tetro is correct, and create a chainlist of
**	all the tetrominos.
**
**	@param: the file descriptor
**
**	@out: the tetominos chainlist
*/

t_tetro		*check_and_save_content(int fd)
{
	char	s[21];
	int		rd;
	char	**tmp;
	t_tetro	*tet;
	int		ret[2];

	tet = NULL;
	if (fd != -1)
	{
		ret[0] = 0;
		ret[1] = 0;
		while (((rd = read(fd, s, 21)) > 0) && (ret[0] != -1) && ++ret[1] < 27)
		{
			ret[0] = rd;
			s[rd] = '\0';
			tmp = ft_strsplit(s, '\n');
			(check_form(tmp) == 1) ? addtet(&tet, tmp) : (ret[0] = -1);
		}
		close(fd);
		if (ret[0] != 20 || ret[1] > 26)
			tet = custom_free(tet);
	}
	return (tet);
}
