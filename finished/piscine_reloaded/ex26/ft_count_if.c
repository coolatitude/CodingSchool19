/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:45:42 by pvanderl          #+#    #+#             */
/*   Updated: 2018/10/01 15:46:39 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int a;
	int number;

	number = 0;
	a = 0;
	while (tab[a] != 0)
	{
		if (f(tab[a]) == 1)
			number++;
		a++;
	}
	return (number);
}
