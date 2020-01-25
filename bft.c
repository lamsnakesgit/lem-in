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
/*int 			bfs(t_llrc *llrc)
{
	t_rooms		**q;
	t_list 		*neighbours;
	t_rooms 	*tmp;
	int 		*vis;
	int 		i;

	q = queuefill(q, llrc);
	tmp = (llrc->fr);
	vis = (int *)malloc(sizeof(int) * llrc->rmi);
	q[0] = tmp;
	i = 0;
	while (q[i] != 0)
	{
		q[i] = 0;
		tmp = (llrc->fr);
	//	++i;
		neighbours = tmp->ln;
		while (neighbours)//((*tmp)->ln)
		{
			q[i] = (t_rooms *)neighbours->content;
			++i;
		}
		tmp = (t_rooms *)(tmp->ln->content);
	}
	return (0);
}*/


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
t_list 			*q_create(t_list *q)
{

}*/

int 			queadd(t_list **q, t_list *tr)
{
	t_list	*tmp;

	if (q && *q)
	{
		tmp = (*q);
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew((void *)tr->content, (size_t)sizeof(tr));//q_create(q, ft_lstadd(((void *)tr->content), (size_t)(sizeof(tr->content)));
		tmp->next->content = (void *)tr->content;
	}
	else
	{
		(*q) = ft_lstnew((void *)tr->content, (size_t)sizeof(tr));//
		(*q)->content = (void*)tr->content;
	}
	return 0;
}
/*
int				quepush(t_llrc *llrc, t_list **q, t_list *tr)//levels mark;add to queue
{
	t_list *ln;

	ln = ((t_rooms *)(tr->content))->ln;
	while (ln)
	{
		if (llrc->er == (t_rooms *)ln->content)//if (llrc->er == (t_rooms *)tr->content)
		{
			((t_rooms *) tr->content)->lvl = -1;//((t_rooms *)tr->content)->lvl + 1;
		}
		else if (llrc->fr == (t_rooms *)ln->content)
		{
			((t_rooms *)ln->content)->lvl = -1;//((t_rooms *)tr->content)->lvl + 1;
		}
		else
		{
			((t_rooms *)ln->content)->lvl = ((t_rooms *)tr->content)->lvl + 1;
			queadd(q, tr);
		}
		ln = ln->next;
	}
	return 0;
}
*/
