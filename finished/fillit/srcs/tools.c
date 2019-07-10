/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:47:14 by pvanderl          #+#    #+#             */
/*   Updated: 2018/12/17 15:00:16 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	function table_len
**
**	@param: a pointer on a table of char
**
**	@out:	the size of the first dimmention of table
*/

int			table_len(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
**	funcion	free_table
**
**	@param:	a pointer to the table to free
**
**	@out:	0 by default
*/

int			free_table(char ***fr)
{
	int i;

	i = 0;
	while ((*fr)[i])
	{
		free((*fr)[i]);
		i++;
	}
	free(*fr);
	return (0);
}

/*
**	function t_tetro_new
**
**	@param:	a table of char
**
**	@out:	a pointer on a new t_tetro element with param1 as piece
*/

t_tetro		*t_tetro_new(char **s)
{
	t_tetro		*tet;

	tet = (t_tetro *)malloc(sizeof(t_tetro));
	if (tet != NULL)
	{
		tet->next = NULL;
		tet->first_i = -1;
		tet->first_j = -1;
		tet->last_i = -1;
		tet->last_j = -1;
		tet->piece = s;
	}
	return (tet);
}

/*
**	function t_tetro_add
**
**	add a chained list element at the end of the list
**
**	@param: a pointer to the first tetro of the list
**	@param: a pointer to the tetro structure to add to the list
**
**	@out:	/
*/

void		t_tetro_add(t_tetro **tet, t_tetro *tetro)
{
	t_tetro	*tmp;

	if (tet != NULL)
	{
		tmp = *tet;
		if (tmp != NULL)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = tetro;
		}
		else
			*tet = tetro;
	}
}

/*
**	function custom_free
**
**	free a list of t_tetro elements
**
**	@param:	a pointer to the firt element of the t_tetro list to free
**
**	@out:	NULL
*/

t_tetro		*custom_free(t_tetro *elem)
{
	int i;

	if (elem != NULL)
	{
		custom_free(elem->next);
		i = 0;
		while (elem->piece[i] != NULL)
		{
			free(elem->piece[i]);
			i = i + 1;
		}
		free(elem->piece);
		elem->next = NULL;
		free(elem);
	}
	return (NULL);
}
