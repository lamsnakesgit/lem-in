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
*/

int                 ispresent(t_llrc *llrc, char *rs)
{
//	t_list  *tmp;
	t_rooms	**tmp;
	int 	i;

	//tmp = llrc->br;
	tmp = llrc->arrrm;
	i = 0;
	while (tmp[i])//((*tmp)[i])
	{
	//	if (ft_strcmp((*tmp)[i]->content, rs) == 0)
	//	if (ft_strcmp((*tmp)[i].name_r, rs) == 0)
		if (ft_strcmp(tmp[i]->name_r, rs) == 0)
		{
			return i;
		}
		++i;
	//	tmp = tmp->next;
	}
	return (-1);
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

int                 corr_link(char **line, t_llrc *llrc, int *rn)//checkmarginindxs
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
	if ((rn[0] = ispresent(llrc, rs)) < 0)
		return 0;
	free (rs);
//	if (ft_strcmp(*line + ))
	++e;
	while ((*line)[i])
		++i;
	rs = ft_strsub(*line, e, i);
	if ((rn[1] = ispresent(llrc, rs)) < 0)
		return 0;
	return 1;
}

t_list				*ft_rlink(/*(t_link **bg*/ t_list **bg, t_rooms *rm)//t_link *new)
{
	if (!bg ||!*bg)
	{
		*bg = ft_lstnew((const void *)rm, (size_t)(sizeof(rm)));
		(*bg)->content = (void *)rm;
		return (*bg);
	}
	else
	{
		ft_lstadd(bg, ft_lstnew((const void *)rm, (size_t)(sizeof(rm))));
		(*bg)->content = (void *)rm;
		return (*bg);
	}
}
void				savelink(t_llrc *llrc, int *rn)
{
/*	t_rooms	**tmp; t_rooms *t0; t_rooms **t1;
*/	t_link	*ln;
/*	tmp = llrc->arrrm;
	t0 = llrc->arrrm[rn[0]];
	t1 = llrc->arrrm[rn[1]];
*/
/*	while (tmp[rn[0]]->ln)
		tmp[rn[0]]->ln = tmp[rn[0]]->ln->next;
	while (tmp[rn[1]]->ln)
		tmp[rn[1]]->ln = tmp[rn[1]]->ln->next;
	llrc->arrrm[rn[0]]->ln = llrc->arrrm[rn[1]];
	llrc->arrrm[rn[0]]->ln->next = 0;
	llrc->arrrm[rn[1]]->ln = llrc->arrrm[rn[0]];
	llrc->arrrm[rn[1]]->ln->next = 0;*/
/*	if (tmp[rn[0]]->ln)
	{
		ft_lstadd(tmp[rn[0]]->ln, tmp[rn[1]]->ln);
	}
	else
	{
		ft_lstnew()
	}
*/
/*
	tmp[rn[0]]->ln = llrc->arrrm[rn[1]];
	tmp[rn[0]]->ln->next = 0;
	tmp[rn[1]]->ln = llrc->arrrm[rn[0]];
	tmp[rn[1]]->ln->next = 0;*/
/*	while (llrc->arrrm[rn[0]]->ln)
		ft_rlink(&(llrc->arrrm[rn[0]]->ln, llrc->arrrm[rn[1]]))*/
	llrc->arrrm[rn[0]]->ln = ft_rlink(&(llrc->arrrm[rn[0]]->ln), llrc->arrrm[rn[1]]);
	llrc->arrrm[rn[1]]->ln = ft_rlink(&(llrc->arrrm[rn[1]]->ln), llrc->arrrm[rn[0]]);
}

int 				nonelink(t_llrc *llrc)
{
	int i;

	i = 0;
	while (llrc->arrrm[i])// && i < llrc->rmi)//ln)//
	{
		if (!llrc->arrrm[i]->ln)
			return (0);
		++i;
	}
	return (1);
}
char 				*linkval(char **line, t_llrc *lrc, int fd)
{
	int ret;
	int rn[2];

	if (!corr_link(/**/line, lrc, rn))
		return 0;
	savelink(lrc, rn);
	free(*line);
	while (get_next_line(fd, line) > 0)
	{
		if ((ret = comstend(*line))==0||ret==-3)
			free (*line);
		else if (ret == -2 || ret == -1)
			return (0);
		else
		{
			if (!corr_link(line, lrc, rn))
				return 0;
			savelink(lrc, rn);
		}
	}
//	print_l(lrc);
	if (!nonelink(lrc))
		return (0);
	return (*line);
}
