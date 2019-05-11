/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:51:23 by pvanderl          #+#    #+#             */
/*   Updated: 2018/10/01 17:32:44 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

int		main(int ac, char **av)
{
	char	table[101];
	int		file;
	int		n;

	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		file = open(av[1], O_RDONLY);
		if (file != -1)
		{
			n = read(file, table, 100);
			table[n] = '\0';
			while (n)
			{
				ft_putstr(table);
				n = read(file, table, 100);
				table[n] = '\0';
			}
		}
	}
	return (0);
}
