/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:32:48 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/24 21:33:07 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** delete links, rooms, ptr, name,
*/
t_rooms 		**queuefill(t_rooms **qu, t_llrc *llrc)
{
	t_rooms		**q;
	int			i;

	q = (t_rooms **)malloc(sizeof(t_rooms *) * llrc->rmi);
	i = 0;
	q[0] = (llrc->fr);
	while (/*q[i] &&*/ i < llrc->rmi)
	{
		q[i] = 0;
		++i;
	}
	return (q);
}

/*
** add root to que beg first el
 * while q-not empty
 * pop (element)//take out -> look up nhbrs//recopy que to beg
 * 	while (el-neighbours)
 * 		push neighbors
*/

/*
** create link ist
** add first rm there
** while (q)
**  pop q
 * 	while q.nbrs
 * 		if (notvis
 * 			push q.nbr
*/
/*t_list 			*queue_add(t_list *st, t_list)
{
	;
}*/
t_list 			*pullnode(t_list **q)
{
	t_list	*h;

	h = 0;
	if (q && *q)
	{
		h = *q;
		//	if ((*q)->next)
		(*q) = (*q)->next;
	}
	return (h);
}
/*
** receive que-ptr, current node pull off que
** save links in tmp to iterate through neighbours;
** if curr link pts to unvis room; mark level; add to the end of que
**
*/
int 			quepush(t_llrc *llrc, t_list **q, t_list *tr)//**tr)///push unvis nbrs
{//add to qu non vis /add levl marks
	t_list	*ln;

	ln = ((t_rooms *)((tr)->content))->ln;//((t_rooms *)tr)->ln;
	int i = 0;
	while (ln)
	{
		if (((t_rooms *)(ln->content))->vis == 0 && ln->content_size != -1)//(((t_rooms *)(*tr)->content)->vis == 0);
		{//links of end/st/dead
			//	if (((t_rooms *)(*tr)->content)->nu//(((t_rooms *)ln->content)->nu == llrc->fr->nu)
			//		((t_rooms *)ln->content)->lvl
			((t_rooms *)ln->content)->lvl = ((t_rooms*)(tr)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ln);//->content);//tr);//add room->q
		}
		ln = ln->next;
		++i;
	}
	return 0;
}

int 			queadd(t_list **q, t_list *tr)
{
	t_list	*tmp;

	if (q && *q)
	{
		tmp = (*q);
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew((void *)tr->content, (size_t)sizeof(tr));
		tmp->next->content = (void *)tr->content;
	}
	else
	{
		(*q) = ft_lstnew((void *)tr->content, (size_t)sizeof(tr));//
		(*q)->content = (void*)tr->content;
	}
	return 0;
}

t_list 			*bfss(t_llrc *llrc)
{
	t_list	*q;
	t_list	*cur;
	t_list	*last;
	int 	f;
	int i = 0;

	q = 0;
	clean(llrc, &q);
	f = 0;
	last = 0;
	while (q != 0)
	{
		++i;
		cur = pullnode(&q);
//		if (f == 0 && ((t_rooms*)cur->content)->vis2 == 1 && cur->content != llrc->fr)
//			bft2(&f, cur, &q, llrc);
		if (ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->er->name_r) && ((t_rooms *)(cur->content))->nu)
			quepush(llrc, &q, cur);
		else
			last = cur;
	}
	print_l(llrc);
	return (last);
}