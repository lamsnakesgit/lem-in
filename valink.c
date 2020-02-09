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
** when & where save link to linked room s? when both linked rms are ok
** better checl nu
*/

/*
** line - contains no room/!' '/'-'/ mb linked roomsnames
** we now have to check rooms presence in all linkes
** duplicate names?
*/

/*
** linkval: first - check1st line
** rm presence /path to itself
** //checkmarginindxs
*/

int					corr_link(char **line, t_llrc *llrc, int *rn)
{
	int		i;
	int		e;
	char	*rs;

	if (!ft_strchr(*line, '-') || ft_strrchr(*line, ' '))
		return (0);
	i = 0;
	while ((*line)[i] && (*line)[i] != '-')
		++i;
	e = i;
	if (!(rs = ft_strsub(*line, 0, i)))
		return (0);
	if ((rn[0] = ispresent(llrc, rs)) < 0)
		return (0);
//	free (rs);
	++e;
	i = e;
	while ((*line)[e])
		++e;
	rs = ft_strsub(*line, i, e - i);
	if ((rn[1] = ispresent(llrc, rs)) < 0)
		return (0);
	return (1);
}

t_list				*ft_rlink(t_list **bg, t_rooms *rm)
{
	if (!bg || !*bg)
	{
		*bg = ft_lstnew((const void *)rm, (size_t)(sizeof(rm)));
		return (*bg);
	}
	else
	{
		ft_lstadd(bg, ft_lstnew((const void *)rm, (size_t)(sizeof(rm))));
		return (*bg);
	}
}

void				savelink(t_llrc *llrc, int *rn)
{
	t_rooms *rm;

	rm = llrc->arrrm[rn[1]];
	llrc->arrrm[rn[0]]->ln = ft_rlink(&(llrc->arrrm[rn[0]]->ln), rm);
	rm = llrc->arrrm[rn[0]];
	llrc->arrrm[rn[1]]->ln = ft_rlink(&(llrc->arrrm[rn[1]]->ln), rm);
}

int					nonelink(t_llrc *llrc)
{
	int i;

	i = -1;
	while (++i < llrc->rmi)
		if (!llrc->arrrm[i]->ln)
			return (0);
	return (1);
}

char				*linkval(char **line, t_llrc *lrc)
{
	int ret;
	int rn[2];
	int i;

	i = 0;
	if (!corr_link(line, lrc, rn))
		return (0);
	savelink(lrc, rn);
	i = 1;
	while (line[i])
	{
		ret = comstend(line[i]);
		if (ret == -2 || ret == -1)
			return (0);
		else if (ret == 1)
		{
			if (!corr_link(line + i, lrc, rn))
				return (0);
			savelink(lrc, rn);
		}
		++i;
	}
	if (!nonelink(lrc))
		return (0);
	return (*line);
}
