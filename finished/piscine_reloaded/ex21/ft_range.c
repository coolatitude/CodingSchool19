/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:12:37 by pvanderl          #+#    #+#             */
/*   Updated: 2018/10/01 17:06:26 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range;
	int		i;

	i = 0;
	if (max - min <= 0)
		return ((void *)0);
	range = malloc(sizeof(int) * (max - min));
	while (min <= max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
