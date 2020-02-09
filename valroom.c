/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valroom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:11:35 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/08 18:53:47 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** if not - or order or comment above ants -> display ERROR?
** read next_line -> either "name_c-x_c-y" or "##start"/"##end"/"#"comment;
** if at least one space contained -> rooms mb;else -> check_##/start/end/commet
** * then links: "name-1_name-2"
** /submodeuls if u lno how to exec i will exec ,inflesliu
** also have to save fir-last rooms
** rooms: own gnl cycle : if comm/st/end slip; if st/end -> next? saveline
** else check_r-coords & save in lst
** - room that has no link?
*/

t_rooms				*ft_room(t_rooms *rm, char **roomcor, t_llrc *llrc)
{
	int i;

	if (!((rm) = (t_rooms *)malloc(sizeof(t_rooms))))
		return (0);
	(rm)->ln = 0;
	(rm)->name_r = ft_strdup(roomcor[0]);
	(rm)->lvl = -1;
	(rm)->vis = 0;
	(rm)->x = ft_atoi(roomcor[1]);
	(rm)->y = ft_atoi(roomcor[2]);
	i = -1;
	while (roomcor[++i])
	{
		free(roomcor[i]);
	}
	free(roomcor);
	if (!checkcor(rm, llrc))
		return (0);
	return (rm);
}

/*
** may erase lst elems right away; arr roomcor
*/

t_list				*valroom_fill1(t_list **br, char **roomcor, t_llrc *llrc)
{
	t_rooms	*rm;

	rm = 0;
	rm = ft_room(rm, roomcor, llrc);
	if (!rm)
		return (0);
	if (!br || !*br)
	{
		*br = ft_lstnew((void *)rm, (size_t)sizeof(rm));
		(*br)->content = (void *)rm;
		return (*br);
	}
	else
	{
		ft_lstadd(br, ft_lstnew((void *)rm, (size_t)sizeof(rm)));
		(*br)->content = (void *)rm;
		return (*br);
	}
	return (0);
}

/*
** send line ->check val inters->check coords;
** save r_name/room in linst;return->link1?
** delete- if nonval rmcor
*/

char				**valrmc_s(char *line, t_llrc *llrc)
{
	char	**roomcor;
	int		i;

	i = 0;
	if (!issplitsp(line, ' '))
		return (0);
	if (!(roomcor = ft_strsplit(line, ' ')))
		return (0);
	while (roomcor[i])
		++i;
	if (i == 3 && roomcor[0][0] != 'L' && validate(3, roomcor + 1, -1, 0))
		return (roomcor);
	freelrm(llrc);
	ft_cleanmem(roomcor);
	return (NULL);
}

int					savemarg(t_llrc *lrc, int cm)
{
	t_rooms *x;

	x = (t_rooms *)lrc->br->content;
	x->lvl = 0;
	if (cm == -1)
		lrc->fr = x;
	if (cm == -2)
		lrc->er = x;
	return (-11);
}

int					turninarr(t_llrc *llrc)
{
	int		i;
	t_list	*tmp;

	if (!(llrc->arrrm = (t_rooms **)malloc(sizeof(t_rooms *) * (llrc->rmi))))
		return (0);
	tmp = llrc->br;
	i = 0;
	while (llrc->br)
	{
		tmp = llrc->br->next;
		llrc->arrrm[i] = (t_rooms *)llrc->br->content;
		llrc->arrrm[i]->nu = i;
		llrc->arrrm[i]->ant = 0;
		llrc->arrrm[i]->vis2 = 0;
		free(llrc->br);
		llrc->br = tmp;
		++i;
	}
	return (1);
}
