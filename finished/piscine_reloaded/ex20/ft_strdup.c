/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:39:44 by pvanderl          #+#    #+#             */
/*   Updated: 2018/10/01 17:02:25 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		i;

	i = 0;
	while (src[i])
		i++;
	s = malloc(sizeof(src));
	s[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	return (s);
}
