/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:27:04 by pvanderl          #+#    #+#             */
/*   Updated: 2018/10/01 14:39:24 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 == *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

void	ft_swap(char **s1, char **s2)
{
	char *s;

	s = *s1;
	*s1 = *s2;
	*s2 = s;
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	ac--;
	av++;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (0 > ft_strcmp(av[i], av[i - 1]))
			{
				ft_swap(av + i, av + i - 1);
				i = 0;
			}
			i++;
		}
	}
	i = 0;
	while (i < ac)
		ft_putstr(av[i++]);
	return (0);
}
