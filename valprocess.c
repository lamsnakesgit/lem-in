/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:27:36 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/16 23:34:19 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#define BS 16000//9000//14000//140000//13000//10000//5000//200//100//16000

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

int 			checkmap(char **ls, char *buf)
{
	int i;
	int j;
	int s;

	i = -1;
	j = 0;
	ls[0] = buf;
	s = -1;//0;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
		//	if (i == 1)
			if (i - s < 2)//== 0)
				return (0);
			s = i;
			buf[i] = 0;
			if (buf[i + 1] == 0)
			{
				ls[++j] = 0;
				return 1;//(ls);
			}
			if (buf[i + 1] == '\n' || !i)// || s - i == 0)
				return (0);
		//	buf[i] = 0;
			ls[++j] = buf + i + 1;//s c
		}
	}
	ls[++j] = 0;
	return (1);//(ls);//WTF
}

char			**processmap(int fd, t_llrc *llrc)
{
	char	buf[BS + 1];
	int		ret;
 	char	*cp;//
 	char	*sv;
 	char 	**ls;

 	cp = ft_strnew(0);
	while ((ret = read(fd, buf, BS)) > 0)
	{
		buf[ret] = 0;//[BS] = 0;
		sv = ft_strjoin(cp, buf);
		free(cp);
		cp = sv;
	}
	if (!cp)
		free(cp);
	if (ret < 0)
		return 0;
//	printf("%s\n", cp);
	ls = lines(cp);//(buf);
	checkmap(ls, cp);
	int i = 0;
/*	while (ls[i])
	{
		printf("=%s\n", ls[i++]);
	}
*/	int j = 0;
	while (ls[0][j])
	{
		if (!ft_isdigit(ls[0][j]))//intlon
			return(0);//ft_err());
		++j;
	}
	llrc->ants = ft_atoi(ls[0]);
	//val
	//print array chekk
	return ls;
}
