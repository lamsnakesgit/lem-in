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
**
*/
int 			bfs(t_llrc *llrc)
{//	t_rooms		**q;
	t_list		*q;
	t_list 		*neighbours;
	t_rooms 	*tmp;//int 		*vis;

	tmp = (llrc->fr);//	vis = (int *)malloc(sizeof(int) * llrc->rmi);//	unvisit(vis, llrc);
	q = ft_lstnew((void *)llrc->fr, (size_t)llrc->fr);

	return 0;
}
int				alg(t_llrc *llrc)
{
	int i;

//	print_l(llrc);
	bfs(llrc);//bfs = (llrc);
	while (1)
	{
		break;
	}
	return 1;
}
