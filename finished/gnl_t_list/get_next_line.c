/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:13:26 by pvanderl          #+#    #+#             */
/*   Updated: 2018/11/06 09:06:50 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	function get_file
**
**	return the link wich as the specified file descriptor as content_size
**
**	@param: a pointer on the first element of the linked list
**	@param: the file descriptor as an int
**
**	@out:	the t_list element matching
*/

static t_list			*get_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

/*
**	function rm_file
**
**	remove the link wich as the specified file descriptor as content_size
**
**	@param: a pointer on the first element of the linked list
**	@param: the file descriptor as an int
**	@param:	the int to return
**
**	@out:	param 3
*/

static int				rm_file(t_list **elem, int fd, int i)
{
	t_list	*past;
	t_list	*curr;

	curr = *elem;
	if ((int)curr->content_size == fd)
	{
		*elem = curr->next;
		free(curr->content);
		free(curr);
		return (i);
	}
	past = curr;
	while ((curr = curr->next))
	{
		if ((int)curr->content_size == fd)
		{
			past->next = curr->next;
			free(curr->content);
			free(curr);
			return (i);
		}
		past = curr;
	}
	return (i);
}

/*
**	function separate
**
**	separate the content of the t_list. then set the first part to the line,
**	and the second part to the content of t_list
**
**	@param: a pointer on a char chain
**	@param: the t_list element with the current file descritor as content_size
**	@param:	a pointer on the first elem of the list
**	@out:	the int of return of get_next_line
*/

static int				separate(char **line, t_list *actual, t_list **elem)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!(ft_strchr(actual->content, (int)'\n')))
	{
		i = ft_strlen(actual->content);
		j = i;
	}
	else
	{
		i = (size_t)(ft_strchr(actual->content, (int)'\n') -
					(char *)actual->content);
		j = i + 1;
	}
	if (!(*line = ft_strnew(i)))
		return (rm_file(elem, actual->content_size, -1));
	*line = ft_strncpy(*line, actual->content, i);
	if (!(s = ft_strnew(ft_strlen((actual->content) + j))))
		return (rm_file(elem, actual->content_size, -1));
	s = ft_strcpy(s, (actual->content + j));
	free(actual->content);
	actual->content = s;
	return (rm_file(elem, actual->content_size, 1));
}

/*
**	function get_next_line
**
**	get a line from a file descriptor and assigns a pointer to
**	the designated found line
**
**	@param: file descriptor int
**	@param: pointer to a to a char chain
**
**	@out:	int if succeed (1), end of file (0) or error (-1)
*/

int						get_next_line(const int fd, char **line)
{
	int				retrn;
	t_list			*actual;
	char			buf[BUFF_SIZE + 1];
	char			*s;
	static t_list	*file;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	actual = get_file(&file, fd);
	while ((retrn = read(fd, buf, BUFF_SIZE)))
	{
		buf[retrn] = '\0';
		s = actual->content;
		if (!(actual->content = ft_strjoin(s, buf)))
			return (rm_file(&file, fd, -1));
		free(s);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (retrn < BUFF_SIZE && !ft_strlen(actual->content))
		return (rm_file(&file, fd, 0));
	return (separate(line, actual, &file));
}
