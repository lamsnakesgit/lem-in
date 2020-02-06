/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valroom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:11:35 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/06 16:12:02 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
/*
** if not - or order or comment above ants -> display ERROR?
** read next_line -> either "name_c-x_c-y" or "##start"/"##end"/"#"comment;
** if at least one space contained -> rooms mb; else -> check_##/start/end/commet#
** * then links: "name-1_name-2"
** /submodeuls if u lno how to exec i will exec ,inflesliu
** also have to save fir-last rooms
** rooms: own gnl cycle : if comm/st/end slip; if st/end -> next? saveline
** else check_r-coords & save in lst
** - room that has no link?
*/

t_rooms				*ft_room(t_rooms *rm, char **roomcor)
{
	if (!((rm) = (t_rooms *)malloc(sizeof(t_rooms))))
		return (0);
	(rm)->ln = 0;
	(rm)->name_r = ft_strdup(roomcor[0]);
	(rm)->lvl = -1;
	(rm)->vis = 0;
	(rm)->x = ft_atoi(roomcor[1]);
	(rm)->y = ft_atoi(roomcor[2]);
	int i = -1;
	while (roomcor[++i])
	{
		free(roomcor[i]);
	}
	free(roomcor);
	return (rm);//return 0;//
}
/*
** may erase lst elems right away; arr roomcor
*/
t_list              *valroom_fill1(t_list **br, /*t_rooms *r,*/ char **roomcor)
{
	char **rmc;
	t_rooms	*rm;

//(t_rooms *)malloc(sizeof(t_rooms))
	rmc = roomcor;//
	rm = 0;
	rm = ft_room(rm, roomcor);
	if (!rm)
		return 0;
	if (!br || !*br)
	{
		*br = ft_lstnew((void *)rm, (size_t)sizeof(rm));
		//ft_lstnew((const void *));//((const void *)roomcor, (size_t)sizeof(roomcor));
		(*br)->content = (void *)rm;//roomcor;
		return (*br);
	}
	else
	{
		//br = br->next;//ft_lstadd(br, ft_lstnew((const void *)rmc, (size_t)sizeof(rmc)));//br);
		ft_lstadd(br, ft_lstnew((void *)rm, (size_t) sizeof(rm)));
		(*br)->content = (void *)rm;//!
		return (*br);
	}
	return (0);
}

int					val_cord(char **roomcor)//ps related neg int?
{
	int		j;

	j = -1;
	while (roomcor[1][++j])
	{
		if (j == 10)
			if (!ft_isdigit(roomcor[1][j]) && ft_cleanmem(roomcor))
				return (ft_err());//0?
	}
	j = -1;
	while (roomcor[2][++j])
		if (!ft_isdigit(roomcor[2][j]) && ft_cleanmem(roomcor))
			return (ft_err());
	return (1);
}

/*
**send line ->check val inters->check coords; save r_name/room in linst;return->link1?
** delete- if nonval rmcor
*/
/*t_rooms				*/

char				**valrmc_s(char *line)
{
	char	**roomcor;
	int 	i;

	i = 0;
	if (!(roomcor = ft_strsplit(line, ' ')))
		return 0;
	while (roomcor[i])// && roomcor)//uncod j
		++i;
	if (i == 3 && roomcor[0][0] != 'L' && val_cord(roomcor))
		return (roomcor);
	ft_cleanmem(roomcor);
	return (NULL);
}

int					savemarg(t_llrc *lrc, int cm)
{
	t_rooms *x;

//	if (!(x = (t_rooms*)malloc(sizeof(t_rooms))))
//		return 0;
	x = (t_rooms *)lrc->br->content;
	x->lvl = 0;//?
	if (cm == -1)
		lrc->fr = x;
	if (cm == -2)
		lrc->er = x;
	return -11;
}

void				turninarr(t_llrc *llrc)
{
	int     i;
	t_list  *tmp;
	//llrc->arrrm = (t_rooms *)malloc(sizeof(t_rooms));// * (llrc->rmi - 1));
	if (!(llrc->arrrm = (t_rooms **)malloc(sizeof(t_rooms *) * (llrc->rmi))))
		return ;
	tmp = llrc->br;
	i = 0;
	while (tmp)
	{
		llrc->arrrm[i] = (t_rooms *)tmp->content;
		llrc->arrrm[i]->nu = i;
		llrc->arrrm[i]->ant = 0;
		llrc->arrrm[i]->vis2 = 0;
		tmp = tmp->next;
//		printf("||%s||%d\n", llrc->arrrm[i]->name_r, (llrc->arrrm)[i]->x);
		++i;
	}
}
