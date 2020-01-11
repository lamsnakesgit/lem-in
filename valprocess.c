/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:27:36 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/08 16:49:32 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#define BS 16000
/*
char			**lines(char *buf)
{
	int 	i;
	int		s;
	char	**ls;

	i = -1;
	s = 0;
//	ls = 0;
	while (buf[++i])
		if (buf[i] == '\n')
			++s;
	if (!(ls = (char **)malloc(sizeof(char *) * (s + 2))))
		return (0);
	i = -1;
	while (++i < s + 2)
		ls[i] = (char *)malloc(sizeof(char));//
	return (ls);
}

char			**processmap(int fd)
{
	char	buf[BS + 1];
	int		ret;
 	char	cp[fd];//
 	char	*sv;

 	cp[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BS)) > 0)
	{
		buf[BS] = 0;
		sv = ft_strjoin(cp[fd], buf);
		free(cp[fd]);
		cp[fd] = sv;
	}
	lines(cp[fd]);//(buf);
	return 0;
}*/
