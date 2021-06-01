/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:22:31 by pvanderl          #+#    #+#             */
/*   Updated: 2021/05/31 21:22:32 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

int		ft_atoi_base(char const *str, char const *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void*));
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	main_0(void);
void	printf_list(t_list *list);
void	ft_lstclear(t_list **list);
void	atoi_base(char *s, char *b);

#endif