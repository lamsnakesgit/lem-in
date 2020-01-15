/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:19:18 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/07 18:20:03 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 				print_l(t_llrc *lrc)
{
	t_list *l;
//	l = lrc->arrrm[rn[0]]->ln;
//	l = lrc->arrrm[13]->ln;
//	l = lrc->arrrm[1]->ln;
	int i = 0;
	l = lrc->arrrm[i]->ln;
	while (l)
	{
		while (l) {
			printf("i=%4s|%s\n", lrc->arrrm[i]->name_r,
				   ((t_rooms *) l->content)->name_r);//(t_rooms *)lrc->arrrm[rn[0]]->ln->content->name_r);
			//lrc->arrrm[rn[0]]->ln = lrc-
			l = l->next;
		}
//		printf("""");
		printf("\n");
		++i;
		if (!lrc->arrrm[i])
			break ;
		l = lrc->arrrm[i]->ln;
	}
}
/*
** delete links, rooms, ptr, name,
*/
/*void 			freee(t_llrc *llrc)
{
	llrc->
}*/
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

int 			*unvisit(int *vis, t_llrc *llrc)
{
	int i;

	i = -1;
	while (++i < llrc->rmi)//iter array
		vis[i] = 0;
	return (0);
}
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
		while (tmp)
			tmp = tmp->next;
		tmp = ft_lstnew((void *)tr->content, (size_t)sizeof(tr));//q_create(q, ft_lstadd(((void *)tr->content), (size_t)(sizeof(tr->content)));
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
int 			bfs(t_llrc *llrc)
{//	t_rooms		**q;
	t_list		*q;
	t_list 		*neighbours;
	t_rooms 	*tmp;//int 		*vis;
	t_list		*tr;

	tmp = (llrc->fr);//	vis = (int *)malloc(sizeof(int) * llrc->rmi);//	unvisit(vis, llrc);
	if (!(q = ft_lstnew((void *)llrc->fr, (size_t)(sizeof(llrc->fr)))))
		return (0);
	while (q != 0)///*(qu)/*/(q == 0)// || !q->content)
	{
		tr = pullnode(&q);
		if ((t_rooms *)tr->content != llrc->er)
		{
			quepush(llrc, &q, tr);//put levels; add to queue
		}
		tr = tr->next;
/*		while (((t_rooms*)q->content)->ln)
		{

		}
*/
		break ;
	}
	return 0;
}
/*
** receive que-ptr, current node pull off que
** save links in tmp to iterate through neighbours;
** if curr link pts to unvis room; mark level; add to the end of que
**
*/
int 			quepush(t_llrc *llrc, t_list **qu, t_list *tr)//**tr)///push unvis nbrs
{//add to qu non vis /add levl marks
	t_list	*ln;

	ln = ((t_rooms *)((tr)->content))->ln;//((t_rooms *)tr)->ln;
	while (ln)
	{
		if (((t_rooms *)(ln->content))->vis == 0)//(((t_rooms *)(*tr)->content)->vis == 0);
		{//links of end/st/dead
		//	if (((t_rooms *)(*tr)->content)->nu//(((t_rooms *)ln->content)->nu == llrc->fr->nu)
		//		((t_rooms *)ln->content)->lvl
			((t_rooms *)ln->content)->lvl = ((t_rooms*)(tr)->content)->lvl + 1;
			queadd(qu, ln);//->content);//tr);//add room->q
		}
		ln = ln->next;
	}
	return 0;
}

int 			bft(t_llrc *llrc)
{
	t_list	*qu;
	t_list	*cur;
	t_list	*last;

	if (!(qu = ft_lstnew((void *)llrc->fr, (size_t)(sizeof(llrc->fr)))))
		return 0;
	((t_rooms *)qu->content)->lvl = 0;
	while (qu != 0)
	{
		cur = pullnode(&qu);//node w ptr to first room
		if (ft_strcmp(cur->content, llrc->er->name_r))//if no reach end//add to que non vis
		{
			quepush(llrc, &qu, cur);//((t_rooms *)cur->content)->lvl;
		}
		else
			last = cur;
		cur = cur->next;
	}
	return 0;
}

int				alg(t_llrc *llrc)
{
	int i;

//	print_l(llrc);
//	count_way()
	bft(llrc);
//	bfs(llrc);//bfs = (llrc);
	while (1)
	{
		break;
	}
	return 1;
}
