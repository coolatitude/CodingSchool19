/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:43:56 by pvanderl          #+#    #+#             */
/*   Updated: 2021/06/01 22:30:48 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define FOUT STDOUT_FILENO
# define FIN STDIN_FILENO

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int		ft_strlen(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, char const *src);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(char const *s1);

#endif
