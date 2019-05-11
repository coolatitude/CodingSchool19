/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:09:29 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/27 14:42:56 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	spliter(int **a, int **b, int **s, char *ac)
{
	if (*(ac + 2) == '\0')
	{
		if (*(ac + 1) == 's') // ss
			;
		else if (*ac == 's') // s*
			;//ternaire
		else if (*ac == 'p') // p*
			;
		else if (*(ac + 1) == 'r') // rr
			;
		else
			;
	}
	else // rr*
	{
		if (*(ac + 2) == 'a') // rra
			;
		else if (*(ac + 2) == 'b') // rrb
			;
		else // rrr
			;
	}
}
