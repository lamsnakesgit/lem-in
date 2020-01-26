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

int 		bft2(int *f,t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list	*ln;

	ln = ((t_rooms*)cur->content)->ln;
	while (ln)
	{
		if (((t_rooms*)ln->content)->vis2 == 1 && ln->content != llrc->er
		&& ((t_rooms*)ln->content)->vis != 1)
		{
			((t_rooms *)ln->content)->lvl = ((t_rooms*)(cur)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ( ln));//->content)->ln);
			*f  = 1;
			return (0);
		}
		ln = ln->next;
	}
	return (1);
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

	q = 0;
	clean(llrc, &q);
	f = 0;
	last = 0;
	while (q != 0)
	{
		cur = pullnode(&q);
		if (f == 0 && ((t_rooms*)cur->content)->vis2 == 1 && ((t_rooms*)cur->content)->nu != llrc->er->nu
		&& ((t_rooms*)cur->content)->nu != llrc->fr->nu)
			bft2(&f, cur, &q, llrc);
		else if (ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->er->name_r))
		{
			f = 0;
			quepush(llrc, &q, cur);
		}
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

int  surb2(t_list *ln, t_list *tr2, t_mas *mas)
{
	t_list *ln2;
	t_list *tr;
	int l;

	ln2 = ln;
	l = 0;
	while (ln->next)
	{
		tr = tr2;
		while (tr)
		{
			if (tr->content == ln->content )
			{
				mas->m0 = (t_list *)ln;
				mas->m1 = (t_list *)tr->next;
				ln2->content_size = l;
				return (1);
			}
			tr = tr->next;
		}
		ln = ln->next;
		l++;
	}
	ln2->content_size = l;
	return (0);
}

void surb3(t_list *ln, t_list *tr2, t_mas *mas)
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
				mas->m3 = tr->next;
				return ;
			}
			tr = tr->next;
		}
		ln = ln->next;
		l++;
	}
	ln2->content_size = l;
}


int cross_path(t_list **paths, t_list *ln, t_list *ln2, int f)
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
	return (i);
}
t_list *lastpath(t_list **paths, int i)
{
	t_list *ln;

	ln = *paths;
	if (i == 2)
	{
		while (ln && ln->next && ln->next->next && ln->next->next->next)
		{
			ln = ln->next;
		}
	}
	else if (!i)
	{
		while (ln->next)
			ln = ln->next;
	}
	else
	{
		while (ln->next->next)
			ln = ln->next;
	}
	return (ln);
}
int				path_cmp2(t_llrc *llrc, size_t len)
{
	float l;
	float t;

	if (llrc->psum == 1)
		return 1;
	l = ((float)llrc->ants + (float)llrc->plensum) / (float)llrc->psum;
	t = ((float)llrc->ants + (float)llrc->plensum - (float)len) / (float)llrc->psum;
	return (t >= l);//if t >= l -> break
}
int    path_cmp(int last, t_llrc *llrc, int x)// if t > l то 1 путь лучше, чем 2 остальных
{
	float t;
	float l;

	l = (float)(llrc->ants + llrc->plensum - last + x) / (float)(llrc->psum + 1);
	t = (float)(llrc->ants + llrc->plensum) / (float)llrc->psum;

	return (t > l);
}

void 	delpath(t_list **paths, t_list *ln)
{
	t_list *tr;
	t_list *tr2;

	tr = *paths;
	tr2 = NULL;
	while (tr)
	{
		if (tr == ln)
		{
			if (!tr2)
			{
				(*paths) = (*paths)->next;
				free(tr);
			}
			else
			{
				tr2->next = ln->next;
				free(ln);
			}
			return ;
		}
		tr2 = tr;
		tr = tr->next;
	}
}
void		printallpaths(t_list *ln)//paths)
{
	t_list *path;

	path = ln;
	while (path)
	{
		printflist(path->content);
		printf("\n");
		path = path->next;
	}
}
int surb(t_list **paths, t_llrc *llrc)
{
	t_mas	mas;
	t_list *ln;
	t_list *ln2;
	t_list *tr;
	int i;


	i = -1;
	tr = (*paths);
	ln  = lastpath(paths, 0);
	ln2 = ln;
	while (ln)
	{
		while (tr->next && tr != ln)
		{
			if (surb2(((t_list*)ln->content)->next, ((t_list*)tr->content)->next, &mas))
			{
				i = 0;
				surb3(((t_list*)tr->content)->next, ((t_list*)ln->content)->next, &mas);
				i += cross_path(paths, (t_list *) mas.m0, (t_list *) mas.m1, 0);
				i += cross_path(paths, (t_list *) mas.m2, (t_list *) mas.m3, 1);
				llrc->plensum -= ((t_list*)ln->content)->content_size;
				llrc->psum -= 1;
				delpath(paths, ln);
				if (!path_cmp(((t_list*)tr->content)->content_size, llrc, i))
				{
					ln = lastpath(paths, 1);
					free(ln->next);
					ln->next = NULL;
					ln = lastpath(paths, 1);
					free(ln->next);
					ln->next = NULL; /// psum
				}
				else
				{
					llrc->plensum += i - ((t_list*)tr->content)->content_size;
					llrc->psum += 1;
					printallpaths(*paths);
					delpath(paths, tr);
				}
				ln = lastpath(paths, 2);
				tr = (*paths);
				break;
			}
			tr = tr->next;
		}
		ln = ln->next;
	}
	if (i == -1)
	{
		if (path_cmp2(llrc, ((t_list*)ln2->content)->content_size))
		{
			///вывод муравьев
			return (-1);
		}
	}
	return (i);// if i = 0 то не пересек
}
/*
**
*/

/*
** create list of paths, run pathsearch x times,
 * empty content
** create first node; node->content = npath;
** if (node->next) !node->next = nodewnpath
*/

int				alg(t_llrc *llrc)
{
	int		i;
	int		maxw;
	t_list	*last;
	t_list	*path;
	t_list	*paths;
	int l;
//(t_rooms*)((t_list*)(paths->next->content))->next->content
	maxw = count_way(llrc);//	bfs(llrc);//bfs = (llrc);
	i = 0;
	paths = NULL;
	llrc->plensum = 0;
	while (llrc->psum < maxw)//i < maxw)
	{
		last = bft(llrc);//save x < minw paths; group
		if (!last)
			break ; //no more ways
		path = buildpath(last);
		llrc->plensum += path->content_size;
		llrc->psum += 1;
		printflist(path);
		ft_listup(&paths, path);
		print_l(llrc);
		++i;
		if (!paths->next && llrc->psum < maxw)
		{
			continue ;
		}
		l = surb(&paths, llrc);
	//	return 1;
		//printflist((t_list *)paths->content);
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
	i = -1;
	paths = NULL;
	llrc->plensum = 0;
	llrc->psum = 0;
	while (++i <= maxw)
	{//
		last = bfss(llrc);//save x < minw paths; group
		if (!last) //didnt reach the end
			break ;
		path = buildpath(last);
		llrc->psum++;
		llrc->plensum += path->content_size;//len of all paths if !=
		printflist(path);
		ft_listup(&paths, path);
		if (!paths->next && i < maxw)
			continue ;
//		if (isshorterpath(llrc, path->content_size))
		{
			break ;//run ant
		}
		print_l(llrc);
	}
	return 1;
}

