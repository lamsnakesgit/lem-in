/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:03:11 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/06 16:03:32 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** present rooms are saved into list w link
*/
int                 ispresent(t_llrc *llrc, char *rs)
{
	t_list  *tmp;

	tmp = llrc->br;
	while (tmp)
	{
		if (ft_strcmp(*tmp->content, rs) == 0)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}
/*
 ** line - contains no room/!' '/'-'/ mb linked roomsnames
 ** we now have to check rooms presence in all linkes
 ** duplicate names?
 */
/*
** linkval: first - check1st line
 * rm presence /path to itself
*/

int                 corr_link(char **line, t_llrc *llrc)//checkmarginindxs
{
	int i;
	int e;
	char *rs;

	if (!ft_strchr(*line, '-') || ft_strrchr(*line, ' '))
		return 0;
	i = 0;
	while ((*line)[i] && (*line)[i] != '-')
		++i;
	e = i;
	if (!(rs = ft_strsub(*line, 0, i)))
		return 0;
	if (!ispresent(llrc, rs))
		return 0;
	free (rs);
//	if (ft_strcmp(*line + ))
	++e;
	while ((*line)[i])
		++i;
	rs = ft_strsub(*line, e, i);
	if (!ispresent(llrc, rs))
		return 0;
	return 1;
}

char 				*linkval(char **line, t_llrc *lrc, int fd)
{
	int ret;

	if (!corr_link(/**/line, lrc))
		return 0;
	free(*line);
	while (get_next_line(fd, line) > 0)
	{
		if ((ret = comstend(*line))==0||ret==-3)
			free (*line);
		else if (ret == -2 || ret == -1)
			return (0);
		else
		if (!corr_link(line, lrc))
			return 0;
	}
	return (*line);
}
