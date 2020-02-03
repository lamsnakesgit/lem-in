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
	int 	i;

	i = 0;
	while (i < llrc->rmi)//(llrc->arrrm[i])//((*tmp)[i])
	{
	//	if (ft_strcmp((*tmp)[i]->content, rs) == 0)
	//	if (ft_strcmp((*tmp)[i].name_r, rs) == 0)
		if (ft_strcmp(llrc->arrrm[i]->name_r, rs) == 0)
		{
			free(rs);
			return i;
		}
		++i;
	//	tmp = tmp->next;
	}
	free(rs);
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
//	free (rs);
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
		*bg = ft_lstnew(( void *)rm, (size_t)(sizeof(rm)));
		(*bg)->content = (void *)rm;
		return (*bg);
	}
	else
	{
		ft_lstadd(bg, ft_lstnew(( void *)rm, (size_t)(sizeof(rm))));
		(*bg)->content = (void *)rm;
		return (*bg);
	}
}
void				savelink(t_llrc *llrc, int *rn)
{
	llrc->arrrm[rn[0]]->ln = ft_rlink(&(llrc->arrrm[rn[0]]->ln), llrc->arrrm[rn[1]]);
	llrc->arrrm[rn[1]]->ln = ft_rlink(&(llrc->arrrm[rn[1]]->ln), llrc->arrrm[rn[0]]);
}

int 				nonelink(t_llrc *llrc)//doublewaylink
{
	int i;

	i = -1;
	while ( ++i < llrc->rmi)//llrc->arrrm[++i])//(llrc->arrrm[++i]) &&)//ln)//
		if (!llrc->arrrm[i]->ln)
			return (0);
	return (1);
}

int					copyse(t_llrc *llrc)
{
	int i;

	i = 0;
	while (i < llrc->rmi)
	{
		if (!ft_strcmp(llrc->arrrm[i]->name_r, llrc->fr->name_r))
			llrc->fr->ln = llrc->arrrm[i]->ln;
		else if (!ft_strcmp(llrc->arrrm[i]->name_r, llrc->er->name_r))
			llrc->er->ln = llrc->arrrm[i]->ln;
		++i;
	}
	while (i < llrc->rmi)
	{
		if (llrc->arrrm[i]->nu == llrc->fr->nu)
			llrc->fr->ln = llrc->arrrm[i]->ln;
		else if (llrc->arrrm[i]->nu == llrc->er->nu)
			llrc->er->ln = llrc->arrrm[i]->ln;
	}//
	return (1);
}

char 				*linkval(char **line, t_llrc *lrc, int fd)
{
	int ret;
	int rn[2];
	int i;

	i = 0;
	if (!corr_link(/**/line, lrc, rn))
		return 0;
	savelink(lrc, rn);//	free(*line);
	i = 1;
	while (line[i])//(get_next_line(fd, line) > 0)
	{
		ret = comstend(line[i]);
		//if ((ret = comstend(*line))==0||ret==-3)
		//	free (*line);
		/*else*/ if (ret == -2 || ret == -1)
			return (0);
		else if(ret == 1)//else ok
		{
			if (!corr_link(line + i, lrc, rn))//
				return 0;
			savelink(lrc, rn);
		}
		++i;
	}
//	print_l(lrc);
	if (!nonelink(lrc))
		return (0);//do we check it?
	copyse(lrc);
	return (*line);
}
