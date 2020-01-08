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

int				lines(char *buf)
{
	int i;
	int s;

	i = 0;
	s = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			++s;
		++i;
	}
	return (s);
}

char			**processmap(int fd)
{
	char	buf[BS + 1];
	int		ret;

	while ((ret = read(fd, buf, BS)) > 0)
	{
		buf[BS] = 0;
	}
	lines(buf);
	return 0;
}
