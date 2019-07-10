/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 09:35:56 by pvanderl          #+#    #+#             */
/*   Updated: 2019/05/28 15:07:19 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define PA 1
# define PB 2
# define SA 3
# define SB -3
# define SS 30
# define RA 4
# define RB -4
# define RR 40
# define RRA 5
# define RRB -5
# define RRR 50

typedef struct	s_action
{
	int				action;
	struct s_action	*next;
}				t_action;

/*
**	a		stack a
**	b		stack b
**	size_a	entire size of a
**	size_b	entire size of b
**	sa		size of current part of a
**	sb		sizes of b
**  status  1 = OK
**          2 = KO
**  checker 1 for checker
**	size_sb	number of sizes of b
*/

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			*sb;
	int			sa;
	int			size_sb;
	int			size_a;
	int			size_b;
	int			status;
	int			checker;
	t_action	*actions;
}				t_stack;

#endif
