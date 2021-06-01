/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:23:00 by pvanderl          #+#    #+#             */
/*   Updated: 2021/05/31 21:23:01 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	atoi_base(char *s, char *b)
{
	int	i;

	i = ft_atoi_base(s, b);
	printf("`%s`[%s] = %d\n", s, b, i);
}

/*
** print a list elements one by line
*/
void	printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", (char *)(list->data));
		list = list->next;
	}
}

/*
** free a whole list and it's data field
*/
void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}
