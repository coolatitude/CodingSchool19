/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:44:57 by pvanderl          #+#    #+#             */
/*   Updated: 2018/10/01 16:55:19 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int factorielle;

	if (nb > 12 || nb < 0)
		return (0);
	factorielle = 1;
	i = 0;
	while (++i <= nb)
		factorielle *= i;
	return (factorielle);
}
