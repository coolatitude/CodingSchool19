/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:10:37 by pvanderl          #+#    #+#             */
/*   Updated: 2019/07/18 13:10:39 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_dir(t_global *g, char *dname)
{
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(dname);
	if (!dirp)
		print(NULL, 1, dname);
	else
		while ((dp = readdir(dirp)))
			ft_printf("%s\n", dp->d_name);
	(void)closedir(dirp);
	g = NULL;
}
