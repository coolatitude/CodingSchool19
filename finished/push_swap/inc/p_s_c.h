/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_c.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:05:13 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/11 14:24:45 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_S_C_H
# define P_S_C_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "struct.h"
# include "libft.h"

/*
**	optimisation
**	x functions
*/

int		optimise(t_stack *s);

/*
**	sorting
**	5 functions
*/

void	sort(t_stack *s);

/*
**	se_tools
**	5 functions
*/

void	delete_action(t_action *a);
t_stack	*destroy(t_stack *s);
t_stack	*generate(int size, int checker);
int		print(t_stack *s);
void	add_action(t_stack *s, int n);

/*
**	input_tools
**	4 functions
*/

int		sorted(t_stack *s);
int		check(char *s);
int		add(t_stack *s, int e);
int		tablen(char **s);
void	tabfree(char **s);

/*
**	print_r
**	3 functions
*/

void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);

/*
**	print_rr
**	3 functions
*/

void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);

/*
**	print_sp
**	5 functions
*/

void	pa(t_stack *s);
void	pb(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);

/*
**	start
**	1 function
*/

int		start(int ac, char **av, int checker);

/*
**	sorting_next
**	3 functions
*/

int		delta(int *stack, int nb, int n);
void	push(t_stack *s, int n);
void	pop(t_stack *s);
void	less_than_three(t_stack *s);

/*
**	check_actions
**	3 functions
*/

void	check_actions(t_stack *s);

#endif
