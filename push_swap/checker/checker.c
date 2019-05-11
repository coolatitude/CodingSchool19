/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:33:09 by pvanderl          #+#    #+#             */
/*   Updated: 2019/02/27 14:42:52 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print(int **a, int **b, int **s)
{
	
}

static void	do_op(int **a, int **b, int **s)
{
	char	*line;

	while (get_next_line(1, &line))
	{
		if (!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rra") ||
				!ft_strcmp(line, "rrb") || !ft_strcmp(line, "rr") ||
				!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") ||
				!ft_strcmp(line, "pa") || !ft_strcmp(line, "pb") ||
				!ft_strcmp(line, "ss") || !ft_strcmp(line, "sa") ||
				!ft_strcmp(line, "sb"))
			spliter(a, b, s, line);
		else

	}
}


static int	check(char *s)
{
	
}

int			main(int ac, char **av)
{
	int		a[ac - 1];
	int		sizes[2];
	int		b[ac - 1];

	sizes[0] = ac - 1;
	sizes[1] = 0;
	while (ac > 0)
	{
		if (check(av[ac - 1]))
			a[ac - 2] = ft_atoi(av[ac - 1]);
		else
		{
			sizes[0] = - 1;
			break;
		}
	}
	if (sizes[0] >= 0)
		do_op(&a, &b, &sizes);
	print(&a, &b, &sizes);
	return (0);
}

/*
cas:
sa	swap a[0] and a[1]
sb	swap b[0] and b[1]
ss	sa + sb
pa	push b[0] to a[0]
pb	push a[0] to b[0]

ra	shift a
rb	shift b
rr	ra + rb
rra	shift down a
rrb	shift down b
rrr	rra + rrb
*/
