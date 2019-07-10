/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:58:11 by pvanderl          #+#    #+#             */
/*   Updated: 2018/10/01 14:01:25 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int root;
	int half;

	root = 1;
	half = nb / 2;
	while (root <= half)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}
