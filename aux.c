/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:19:14 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/16 17:25:18 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				count_way(t_llrc *llrc)
{
	int		min;
	t_list	*tf;
	t_list	*te;
	int		f;

	tf = llrc->fr->ln;
	f = 0;
	min = 0;
	while (tf)
	{
		++f;
		tf = tf->next;
	}
	min = llrc->ants > f ? f : llrc->ants;
	te = llrc->er->ln;
	f = 0;
	while (te)
	{
		++f;
		te = te->next;
	}
	min = min > f ? f : min;
	return (min);
}

int				clean(t_llrc *llrc, t_list **q)
{
	int		i;
	t_rooms	*fr;

	fr = llrc->fr;
	(*q) = ft_lstnew((const void *)fr, (size_t)(sizeof((void *)(fr))));
	if (!(*q))
		return (1);
	i = -1;
	while (++i < llrc->rmi)
	{
		llrc->arrrm[i]->vis = 0;
		llrc->arrrm[i]->lvl = 0;
		llrc->arrrm[i]->was = 0;
	}
	(*q)->content = (void *)llrc->fr;
	((t_rooms *)(*q)->content)->vis = 1;
	((t_rooms *)(*q)->content)->ant = 0;
	return (0);
}

/*
** l = // с новым
** return //if t >= l -> break
*/

int				path_cmp2(t_llrc *llrc, size_t len)
{
	float l;
	float t;
	float sum;

	sum = (float)llrc->ants + (float)llrc->plensum;
	if (llrc->psum == 1)
		return (1);
	l = sum / (float)llrc->psum;
	t = (sum - (float)len) / ((float)llrc->psum - 1);
	return (l >= t);
}

/*
** // if t > l то 1 путь лучше, чем 2 остальных
*/

int				path_cmp(int last, t_llrc *llrc, int x)
{
	float t;
	float l;
	float sum;

	sum = (float)(llrc->ants + llrc->plensum);
	l = (float)(sum - last + x) / (float)(llrc->psum + 1);
	t = (float)(llrc->ants + llrc->plensum) / (float)llrc->psum;
	return (t > l);
}

/*
** deletes roomnames, links. array of rooms, pointer to arrrooms
** free lst removed
*/

long			delete_rooms(t_llrc *llrc, int i)
{
	t_list	*tmpbr;
	t_list	*nextbr;
	t_list	*tmp;

	i = 0;
	while (i < llrc->rmi)
	{
		free(llrc->arrrm[i]->name_r);
		while (llrc->arrrm[i]->ln)
		{
			tmp = llrc->arrrm[i]->ln->next;
			free(llrc->arrrm[i]->ln);
			llrc->arrrm[i]->ln = tmp;
		}
		free(llrc->arrrm[i]);
		++i;
	}
	tmpbr = llrc->br;
	while (tmpbr)
	{
		nextbr = tmpbr->next;
		free(tmpbr);
		tmpbr = nextbr;
	}
	free(llrc->arrrm);
	return (0);
}
