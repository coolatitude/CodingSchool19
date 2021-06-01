/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:19:07 by pvanderl          #+#    #+#             */
/*   Updated: 2021/05/30 12:16:14 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void 	len_cpy_cmp_read_write_dup(
		char *s1, char *s2, int is_strlen, int len)
{
	char	buffer[100];

	bzero(buffer, 100);
	if (is_strlen == 1)
		printf("\t`%s` = %d (%d)\n", s1, ft_strlen(s1), (int)strlen(s1));
	else if (is_strlen == 0)
		printf("\t`%s` (%s)\n", ft_strcpy(buffer, s1), s1);
	else if (is_strlen == 2)
	{
		if (!s1 || !s2)
			printf("\t`%s`:`%s` = %d\n", s1, s2, ft_strcmp(s1, s2));
		else
			printf("\t`%s`:`%s` = %d (%d)\n", s1, s2, ft_strcmp(s1, s2),
				strcmp(s1, s2));
	}
	else if (is_strlen == 3)
		printf("\t %zd (`%s`:%d)\n", ft_write(FOUT, s2, len), s2, len);
	else if (is_strlen == 4)
		printf("\t`%s`:%zd\n", buffer, ft_read(FIN, buffer, len));
	else
	{
		s2 = ft_strdup(s1);
		printf("`%s` (`%s`)\n", s2, s1);
		free(s2);
	}
}

static void	main_0(void)
{
	printf("OK\n");
	printf("\nwrite\n");
	len_cpy_cmp_read_write_dup(NULL, "toto", 3, 4);
	len_cpy_cmp_read_write_dup(NULL, "totototo", 3, 4);
	len_cpy_cmp_read_write_dup(NULL, "totototo", 3, 8);
	len_cpy_cmp_read_write_dup(NULL, "toto", 3, 2);
	printf("OK\n");
	printf("\nread (Makefile)\n");
	len_cpy_cmp_read_write_dup(NULL, NULL, 4, 50);
	len_cpy_cmp_read_write_dup(NULL, NULL, 4, 25);
	len_cpy_cmp_read_write_dup(NULL, NULL, 4, 4);
	len_cpy_cmp_read_write_dup(NULL, NULL, 4, 14);
	len_cpy_cmp_read_write_dup(NULL, NULL, 4, 0);
	printf("OK\n");
	printf("\nft_strdup\n");
	len_cpy_cmp_read_write_dup("toto", NULL, 5, 0);
	len_cpy_cmp_read_write_dup("totobar", NULL, 5, 0);
	len_cpy_cmp_read_write_dup("long message", NULL, 5, 0);
	len_cpy_cmp_read_write_dup("", NULL, 5, 0);
	len_cpy_cmp_read_write_dup((char *) NULL, NULL, 5, 0);
	len_cpy_cmp_read_write_dup("long message", NULL, 5, 0);
	printf("-done\n");
}

int	main(void)
{
	printf("strlen\n");
	len_cpy_cmp_read_write_dup("", NULL, 1, 0);
	len_cpy_cmp_read_write_dup("toto", NULL, 1, 0);
	len_cpy_cmp_read_write_dup("HEHEHEHE", NULL, 1, 0);
	len_cpy_cmp_read_write_dup("J'aime 19! c'est une ecole de fous!",
		NULL, 1, 0);
	len_cpy_cmp_read_write_dup("Ils sont fous ces codeurs", NULL, 1, 0);
	len_cpy_cmp_read_write_dup("-1", NULL, 1, 0);
	printf("OK\n");
	printf("\nstrcpy\n");
	len_cpy_cmp_read_write_dup("toto", NULL, 0, 0);
	len_cpy_cmp_read_write_dup("", NULL, 0, 0);
	len_cpy_cmp_read_write_dup("long message", NULL, 0, 0);
	len_cpy_cmp_read_write_dup(NULL, NULL, 0, 0);
	printf("OK\n");
	printf("\nstrcmp\n");
	len_cpy_cmp_read_write_dup("toto", "toto", 2, 0);
	len_cpy_cmp_read_write_dup("", "toto", 2, 0);
	len_cpy_cmp_read_write_dup("toto", "", 2, 0);
	len_cpy_cmp_read_write_dup("toto", "toto Hey", 2, 0);
	len_cpy_cmp_read_write_dup("TOTO", NULL, 2, 0);
	len_cpy_cmp_read_write_dup(NULL, "TOTO", 2, 0);
	len_cpy_cmp_read_write_dup(NULL, NULL, 2, 0);
	main_0();
	return (0);
}
