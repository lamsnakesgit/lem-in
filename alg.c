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

void		bft2(int *f, t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list	*ln;

	ln = ((t_rooms*)cur->content)->ln;
	while (ln)
	{
		if (((t_rooms*)ln->content)->vis2 == 1 && ln->content != llrc->er)
		{
			((t_rooms *)ln->content)->lvl = ((t_rooms*)(cur)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ( ln));//->content)->ln);
			*f = 1;
			return ;
		}
		ln = ln->next;
	}
//	*f = 1;
}

/*
**	if (!ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->fr->name_r))
**		printf("FIRST!\n");
**
*/
t_list 			*bft(t_llrc *llrc)
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
		if (f == 0 && ((t_rooms*)cur->content)->vis2 == 1 && cur->content != llrc->fr)
			bft2(&f, cur, &q, llrc);
		else if (ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->er->name_r))
			quepush(llrc, &q, cur);
		else
			last = cur;
	}
	print_l(llrc);
	return (last);
}

/*
 * go from end-room to level-1 collect path
 */

void			cutpath(t_list **er,t_list *er2)
{
	t_list	*ln;

	ln = ((t_rooms *)(*er)->content)->ln;
	while (ln)
	{
		if (((t_rooms *)(ln)->content) == ((t_rooms *)(er2->content)))
		{
			ln->content_size = -1;
			break;
		}
		ln = ln->next;
	}
}

t_list 			*buildpath(t_list *er)
{
	t_list *ln;
	t_list *path;
	t_list *tmp;
	int i;

	i = 0;
//	crpath(&path, er);
	path = ft_lstnew((void *)er, (size_t) sizeof(path));
	path->content = er->content;
	path->next = 0;
	((t_rooms *)path->content)->vis2 = 1;
	while (((t_rooms *) er->content)->lvl != 0)
	{
		ln = ((t_rooms *) er->content)->ln;
		while (ln)
		{
			if (((t_rooms *) ln->content)->lvl ==
			((t_rooms *) er->content)->lvl - 1)
			{
				cutpath(&ln, er);
				tmp = ft_lstnew((void *)(ln->content),(size_t)(sizeof(er)));
				tmp->content = (void *)ln->content;
				ft_lstadd(&path, tmp);
				i++;
				path->content = (void *)ln->content;
				((t_rooms *)path->content)->vis2 = 1;
				er = ln;
				break;
			}
			ln = ln->next;
		}
	}
	path->content_size = i;
	return (path);
}

void surb2(t_list *ln, t_list *tr2, t_mas *mas, int *i)
{
	t_list *ln2;
	t_list *tr;
	int l;

	ln2 = ln;
	l = 0;
	while (ln)
	{
		tr = tr2;
		while (tr)
		{
			if (tr->content == ln->content)
			{
				mas->m0 = (t_list *)ln;
				*i += 1;
				mas->m1 = (t_list *)tr->next;
				(*i)++;
				return ;
			}
			tr = tr->next;
		}
		ln = ln->next;
		l++;
	}
	ln2->content_size = l;
}

void surb3(t_list *ln, t_list *tr2, t_mas *mas, int *i)
{
	t_list *ln2;
	t_list *tr;
	int l;

	ln2 = ln;
	l = 0;
	while (ln)
	{
		tr = tr2;
		while (tr)
		{
			if (tr->content == ln->content)
			{
				mas->m2 = ln;
				*i += 1;
				mas->m3 = tr->next;
				(*i)++;
				return ;
			}
			tr = tr->next;
		}
		ln = ln->next;
		l++;
	}
	ln2->content_size = l;
}


void inferno(t_list **paths, t_list *ln, t_list *ln2, int f)
{
	t_list *tr;
	t_list *path;
	t_list *main;
	int i;

	i = 0;
	main = NULL;
	if (f)
		tr = (*paths)->content;
	else
		tr = (*paths)->next->content;
	while (tr)
	{
		if (tr->content == ln->content)
		{
			crpath(&path, tr);
			ft_lstadd_up(&main, path);
			tr = ln2;
			i++;
		}
		crpath(&path, tr);
		ft_lstadd_up(&main, path);
		tr = tr->next;
		i++;
	}
	main->content_size = i;
	ft_listup(paths, main);

}
void surb(t_list *ln, t_list *tr, t_list **paths, t_llrc *llrc)
{
	t_mas	mas;
	t_list *ln2;
	int i;
	t_list	*q;

	i = 0;

	surb2(ln->next, tr->next, &mas, &i);
	surb3(tr->next, ln->next, &mas, &i);

	if (i != 0)
	{
		q = (*paths);
		inferno(paths, (t_list *)mas.m0, (t_list *)mas.m1, 1);
		printflist(q->next->next->content);
		printf("\n");
		inferno(paths, (t_list *)mas.m2, (t_list *)mas.m3, 0);
		printflist(q->next->next->next->content);
		ln2  = (*paths)->next->content;
		(*paths)->next =(*paths)->next->next;
		free(ln2);
	}

}
int    apalon(t_list *paths, int ant)// if t > l то 1 путь лучше, чем 2 остальных
{

	float t;
	float l;
	t_list *tr;
	t_list *ln;
	t_list *ln2;

	tr = paths->content;
	l = 0;
	if (paths->next)
	{
		ln = paths->next->content;
		if (paths->next->next && (ln2 = paths->next->next->content))
			l = ((float)(ant + ln->content_size - 1 + ln2->content_size - 1)) / 2;
		else
			l = ant + ln->content_size;
	}
	t = (float)tr->content_size + (float)ant;
	return (t < l);
}

/*
** create list of paths, run pathsearch x times,
 * empty content
** create first node; node->content = npath;
** if (node->next) !node->next = nodewnpath
*/

int				alg(t_llrc *llrc)
{
	int i;
	int maxw;
	t_list	*last;
	t_list	*path;
	t_list	*paths;

//	print_l(llrc);
	maxw = count_way(llrc);//	bfs(llrc);//bfs = (llrc);
	i = 0;
	paths = NULL;
	while (i < maxw)
	{
		last = bft(llrc);//save x < minw paths; group
		if (!last)
			break ; //no more ways
		path = buildpath(last);
		printflist(path);
		ft_listup(&paths, path);
		print_l(llrc);
		if (!paths->next && i < maxw)
		{
			++i;
			continue ;
		}
		surb((t_list *)paths->content, (t_list *)paths->next->content, &paths, llrc);
		print_l(llrc);
		if (apalon(paths, llrc->ants))
		{
			printf("1\n");
			exit(0);
		}//(t_rooms*)((t_list*)(paths->next->content))->next->content
		else
		{
			printf("2\n");
			exit(0);
		}
		//printflist((t_list *)paths->content);
		++i;
	}
	return 1;
}
/*
** run bft to collect list of paths
** block collected
** 0 ants? null rm/link?
** -+coors
** count len path
** run ants through paths
** print_paths
*/

int				alg_alt(t_llrc *llrc)
{
	int i;
	int maxw;
	t_list	*last;
	t_list	*path;
	t_list	*paths;

//	print_l(llrc);
	maxw = count_way(llrc);//	bfs(llrc);//bfs = (llrc);
	i = 0;
	paths = NULL;
	while (i <= maxw)
	{
		last = bft(llrc);//save x < minw paths; group
		path = buildpath(last);
		printflist(path);
		ft_listup(&paths, path);
		print_l(llrc);
		++i;
	}
	return 1;
}

