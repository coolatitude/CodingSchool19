/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:22:18 by pvanderl          #+#    #+#             */
/*   Updated: 2021/05/31 21:22:22 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

/*
** Start !
*/
int	main(void)
{
	printf("\n--ft_atoi_base\n");
	atoi_base("42", "0123456789");
	atoi_base("0", "0123456789");
	atoi_base("1", "0123456789");
	atoi_base("1215415478", "0123456789");
	atoi_base("-0", "0123456789");
	atoi_base("-1", "0123456789");
	atoi_base("-42", "0123456789");
	atoi_base("--42", "0123456789");
	atoi_base("-+-42", "0123456789");
	atoi_base("-+-+-+42", "0123456789");
	atoi_base("-+-+-+-42", "0123456789");
	atoi_base("-1215415478", "0123456789");
	atoi_base("2147483647", "0123456789");
	atoi_base("2147483648", "0123456789");
	atoi_base("-2147483648", "0123456789");
	atoi_base("-2147483649", "0123456789");
	atoi_base("2a", "0123456789abcdef");
	atoi_base("ff", "0123456789abcdef");
	atoi_base("poney", "poney");
	atoi_base("dommage", "invalid");
	atoi_base("dommage", "aussi invalide");
	main_0();
	return (0);
}
