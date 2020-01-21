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

	int i = 0;
	l = lrc->arrrm[i]->ln;
	while (l)
	{
		while (l)
		{
			printf("i=%4s|%6s=|%d\n", lrc->arrrm[i]->name_r,
				   ((t_rooms *) l->content)->name_r,
				   ((t_rooms *) l->content)->lvl);
			l = l->next;
		}
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
	/*	if ((t_rooms *)tr->content != llrc->er)
		{
			quepush(llrc, &q, tr);//put levels; add to queue
		}*/
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
int 			quepush(t_llrc *llrc, t_list **q, t_list *tr)//**tr)///push unvis nbrs
{//add to qu non vis /add levl marks
	t_list	*ln;

	ln = ((t_rooms *)((tr)->content))->ln;//((t_rooms *)tr)->ln;
	int i = 0;
	while (ln)
	{
		if (((t_rooms *)(ln->content))->vis == 0)//(((t_rooms *)(*tr)->content)->vis == 0);
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

t_list 			*bft(t_llrc *llrc)
{
	t_list	*q;
	t_list	*cur;
	t_list	*last;

	if (!(q = ft_lstnew((const void *)llrc->fr, (size_t)(sizeof((void *)(llrc->fr))))))
		return 0;
	q->content = (void *)llrc->fr;
	((t_rooms *)(q->content))->lvl = 0;
	((t_rooms *)q->content)->vis = 1;
	((t_rooms *)q->content)->ant = -999;
	llrc->arrrm[7]->vis = 1;
	llrc->arrrm[7]->lvl = 0;
	llrc->arrrm[7]->ant =555;
	int i = 0;
	while (q != 0)
	{
		++i;
		cur = pullnode(&q);
		if (!ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->fr->name_r))
			printf("FIRST!\n");
		if (ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->er->name_r))
		{
			quepush(llrc, &q, cur);
		}
		else
			last = cur;
	}
	print_l(llrc);
	return (last);
}

int             count_way(t_llrc *llrc)
{
    int		min;
    t_list	*tf;
    t_list	*te;
    int 	f;

    tf = llrc->fr->ln;
	f = 0;
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

void			printflist(t_list *path)
{
	t_list *ln;

	int i = 0;
	ln = path;
	while (ln)
	{
		printf("%s\n", ((t_rooms *)ln->content)->name_r);
		ln = ln->next;
	}
}

t_list 			**buildpath(t_list *er, t_list **path)
{
	t_list	*ln;

	(*path) = ft_lstnew((void*)er, (size_t)sizeof(er));
	(*path)->content = (void*)er;
	while (((t_rooms *)er->content)->lvl != 0)
	{
		ln = ((t_rooms *)er->content)->ln;
		while (ln)
		{
			if (((t_rooms *)ln->content)->lvl == ((t_rooms *)er->content)->lvl - 1)
			{
				ft_lstadd(path, ln->content);
				(*path)->content = ((void*)path, ft_lstnew((void *)ln->content, sizeof(ln->content)));
				er = ln;
				break;
			}
			ln = ln->next;
		}
	}
	return (path);
}
int				alg(t_llrc *llrc)
{
	int i;
	int minw;
	t_list	*last;
	t_list	*path;

//	print_l(llrc);
	minw = count_way(llrc);
	last = bft(llrc);//save x < minw paths; group
//	bfs(llrc);//bfs = (llrc);
	path = *buildpath(last, &path);
	printflist(path);
	while (1)
	{
		break;
	}
	return 1;
}
