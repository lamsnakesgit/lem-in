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

int 		bft2(int *f, t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list	*ln;

	ln = ((t_rooms*)cur->content)->ln;
	while (ln)
	{
		if (((t_rooms*)ln->content)->vis2 == 1 && ln->content != llrc->er
		&& ((t_rooms*)ln->content)->vis != 1 && ln->content_size != -1)
		{
			((t_rooms *)ln->content)->lvl = ((t_rooms*)(cur)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ( ln));//->content)->ln);
			*f = 1;
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
	int f;

	f = 0;
	q = 0;
	clean(llrc, &q);
	last = 0;
	while (q != 0)
	{
		cur = pullnode(&q);
		if (((t_rooms*)cur->content)->vis2 == 1
		&& ((t_rooms*)cur->content)->nu != llrc->er->nu
		&& ((t_rooms*)cur->content)->nu != llrc->fr->nu)
			bft2(&f , cur, &q, llrc);
		if (ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->er->name_r) && f != 1)
		{
			quepush2(llrc, &q, cur);
		}
		else if (((t_rooms*)cur->content)->nu == llrc->er->nu)
			last = cur;
		f = 0;
	}
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
			//	tmp = ft_lstnew((void *)(ln->content),(size_t)(sizeof(er)));
			//	tmp->content = (void *)ln->content;
				ft_lstadd(&path, ft_lstnew((void *)ln->content, (size_t) sizeof(er)));//tmp);//leak
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

/*
**
*/
void			free_paths(t_list *path)
{
	t_list *paths;

//	paths = path;
	while (path)
	{
		paths = path->next;
		free(path->content);
		free(path);
		path = paths;
	}
}
/*
** create list of paths, run pathsearch x times,
** empty content
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

	maxw = count_way(llrc);
	if (!maxw)
		return 0;
	i = 0;
	paths = NULL;
	llrc->plensum = 0;
	llrc->psum = 0;
	while (llrc->psum < maxw)
	{
		if (!(last = bft(llrc)))
			break ;
		path = buildpath(last);
		llrc->plensum += path->content_size;
		llrc->psum += 1;
	//	printflist(path);
		ft_listup(&paths, path);
		++i;
		if (!paths->next && llrc->psum < maxw)
			continue ;
		if (surb(&paths, llrc))
			break;
		//printflist((t_list *)paths->content);
	}
//	printf("\n");
//	printallpaths(paths);
	sort_path(&paths);
	print_ant(&paths, llrc);
	free_paths(paths);
//	delete_rooms(llrc);
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
	while (llrc->psum <= maxw)//(++i <= maxw)
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
		if (path_cmp2(llrc, path->content_size))//if true it didnt get better
			break ;//run ant
	//	print_l(llrc);
	}
	print_ant(&paths, llrc);
	return 1;
}

