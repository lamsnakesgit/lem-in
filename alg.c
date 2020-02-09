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

int 		 bft2(int *f, t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list *ln;

	ln = ((t_rooms *) cur->content)->ln;
	while (ln)
	{
		if (ln->content == llrc->fr || ln->content == llrc->er)
			*f = 1;
		if (((t_rooms *) ln->content)->vis2 == 1 && ln->content_size != -1
		    && ln->content != llrc->fr && ln->content != llrc->er)
		{
			((t_rooms *) ln->content)->lvl = ((t_rooms *) (cur)->content)->lvl + 1;
			((t_rooms *) ln->content)->vis = 1;
			queadd(q, ln);
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
void    dellist(t_list	*ln)
{
	t_list	*tr;
	while (ln)
	{
		tr = ln->next;
		free(ln);
		ln = tr;
	}
}
t_list 			*bft(t_llrc *llrc)
{
	t_list	*q;
	t_list	*cur;
	int f;

	q = NULL;
	f = 0;
	clean(llrc, &q);
	while (q != 0)
	{
		cur = pullnode(&q);
		if (((t_rooms*)cur->content)->vis2 == 1
		&& ((t_rooms*)cur->content)->nu != llrc->er->nu
		&& ((t_rooms*)cur->content)->nu != llrc->fr->nu)
			bft2(&f , cur, &q, llrc);
		if (ft_strcmp(((t_rooms*)cur->content)->name_r, llrc->er->name_r) && f != 1)
			quepush2(llrc, &q, cur);
		else if (((t_rooms*)cur->content)->nu == llrc->er->nu)
		{
			dellist(q);
			return (cur);
		}
		free(cur);
		f = 0;
	}
	return (NULL);
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


t_list 			*findlist(t_list *ln, t_list *er)
{
	t_list *tr;
	t_list *cur;

	tr = NULL;
	cur = NULL;
	while (ln)
	{
		if (((t_rooms *) ln->content)->lvl ==
		    ((t_rooms *) er->content)->lvl - 1
		    && ((t_rooms *)ln->content)->vis2 == 1)
			tr = ln;
		if (((t_rooms *) ln->content)->lvl ==
		    ((t_rooms *) er->content)->lvl - 1
		    && ((t_rooms *)ln->content)->vis2 != 1)
			cur = ln;
		ln = ln->next;
	} //return (tr != NULL ? tr : cur);x§X
    return (cur != NULL ? cur : tr);
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
		ln = findlist(((t_rooms *) er->content)->ln, er);
		cutpath(&ln, er);
		tmp = ft_lstnew((void *) (ln->content), (size_t) (sizeof(er)));
		ft_lstadd(&path, tmp);
		i++;
		path->content = (void *) ln->content;
		((t_rooms *) path->content)->vis2 = 1;
		if (i == 1)
			free(er);
		er = ln;
	}
	path->content_size = i;
	return (path);
}

void            del_paths(t_list *path, t_llrc *llrc)//free paths as wellas path content
{
	t_list  *paths;
	t_list  *ln;
	t_list  *next;

	while (path)
	{
		paths = path->next;
		ln = (t_list *)path->content;
		while (ln)
		{
			next = (t_list *)ln->next;
			free(ln);
			ln = next;
		}
		free(path);
		path = paths;
	}
	delete_rooms(llrc, 0);
	exit(0);
}

int				alg(t_llrc *llrc)
{
	int		i;
	int		maxw;
	t_list	*last;
	t_list	*path;
	t_list	*paths;

	if (!(maxw = count_way(llrc)))
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
        printflist(path);
		ft_listup(&paths, path);
		++i;
		if (!paths->next && llrc->psum < maxw)
			continue ;
		if (surb(&paths, llrc))
			break;
	}
	if (paths)
		print_ant(&paths, llrc);
	ft_err();
	del_paths(paths, llrc);
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
	t_list *last;
	t_list *path;
	t_list *paths;

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
			break;
		path = buildpath(last);
		llrc->psum++;
		llrc->plensum += path->content_size;//len of all paths if !=
		printflist(path);
		ft_listup(&paths, path);
		if (!paths->next && i < maxw)
			continue;
//		if (isshorterpath(llrc, path->content_size))
		if (path_cmp2(llrc, path->content_size))//if true it didnt get better
			break;//run ant
		//	print_l(llrc);
	}
	print_ant(&paths, llrc);
	return 1;
}