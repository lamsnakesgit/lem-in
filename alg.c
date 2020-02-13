/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:19:18 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/09 17:52:35 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** iterate through list of links to find out which link has a link to cur
** aka has link with content_size -1
** to go through that; lvl += cur lvl + 1; vis = 1; add to que particular room
*/

int			bft3(int *f, t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list	*ln;
	t_list	*tr;

	ln = ((t_rooms *)cur->content)->ln;
	while (ln)
	{
		if (ln->content == llrc->fr || ln->content == llrc->er)
			*f = 1;
		tr = ((t_rooms *)ln->content)->ln;
		while (tr)// && tr->next != cur->content)
		{
			if (((t_rooms *)tr->content)->nu == ((t_rooms *)cur->content)->nu \
			&& tr->content != llrc->fr \
			&& ((t_rooms *)tr->content)->vis == 1 \
			&& tr->content_size == (size_t)-1)
			{
				((t_rooms *)tr->content)->lvl = ((t_rooms *)cur->content)->lvl + 1;//tr or ln?
				((t_rooms *)tr->content)->vis = 1;
				queadd(q, ln);
				*f = 1;
				return (0);//break ;
			}
			tr = tr->next;
		}
	//	while (((t_rooms *)cur->content)->ln
	/*	if (((t_rooms *)ln->content)->vis2 == 1
			&& ln->content_size != (size_t)-1
			&& ln->content != llrc->fr
			&& ln->content != llrc->er && *f != 1)
		{
			((t_rooms *)ln->content)->lvl =
					((t_rooms *)(cur)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ln);
			*f = 1;
			return (0);
		}
	*/	ln = ln->next;
	}
	return (1);
}

int			bft2(int *f, t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list	*ln;

	ln = ((t_rooms *)cur->content)->ln;
	while (ln)
	{
		if (ln->content == llrc->fr || ln->content == llrc->er)
			*f = 1;
		if (((t_rooms *)ln->content)->vis2 == 1
				&& ln->content_size != (size_t)-1
				&& ln->content != llrc->fr
				&& ln->content != llrc->er && *f != 1)
		{
			((t_rooms *)ln->content)->lvl =
					((t_rooms *)(cur)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ln);
			*f = 1;
			return (0);
		}
		ln = ln->next;
	}
	return (1);
}

t_list		*bft(t_llrc *llrc)
{
	t_list	*q;
	t_list	*cur;
	int		f;

	if ((f = clean(llrc, &q)))
		return (0);
	while (q != 0)
	{
		cur = pullnode(&q);
		if (((t_rooms *)cur->content)->vis2 == 1
				&& ((t_rooms *)cur->content)->nu != llrc->er->nu
				&& ((t_rooms *)cur->content)->nu != llrc->fr->nu)
			bft3(&f, cur, &q, llrc);
		if (ft_strcmp(((t_rooms *)cur->content)->name_r,
				llrc->er->name_r) && f != 1)
			quepush2(&q, cur);
		else if (((t_rooms *)cur->content)->nu == llrc->er->nu)
		{
			dellist(q);
			return (cur);
		}
		free(cur);
		f = 0;
	}
	return (NULL);
}
int 		clean2(t_llrc *llrc, t_list **q)
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
	//	llrc->arrrm[i]->lvl = 0;
	}
	(*q)->content = (void *)llrc->fr;
	((t_rooms *)(*q)->content)->vis = 1;
	((t_rooms *)(*q)->content)->ant = 0;
	llrc->er->vis2 = 0;//always?
	return (0);
}
t_list 		*bfs(t_llrc *llrc)
{
	t_list	*q;
	t_list	*cur;
	t_list	*last;
	int 	f;
	int i = 0;

	q = 0;
	clean2(llrc, &q);
	f = 0;
	last = 0;
	while (q != 0)
	{
		++i;
		cur = pullnode(&q);
//		if (f == 0 && ((t_rooms*)cur->content)->vis2 == 1 && cur->content != llrc->fr)
//			bft2(&f, cur, &q, llrc);
		if (((t_rooms*)cur->content)->nu != llrc->er->nu)// && ((t_rooms *)(cur->content))->vis2 != 1)//llrc->er->nu)
			quepush3(&q, cur);
		else
			last = cur;
	}
//	print_l(llrc);
	return (last);
	return (0);
}

t_list		*buildpath(t_list *er)
{
	t_list	*ln;
	t_list	*path;
	t_list	*tmp;
	int		i;

	i = 0;
	path = ft_lstnew((void *)er, (size_t)sizeof(path));
	path->content = er->content;
	path->next = 0;
	((t_rooms *)path->content)->vis2 = 1;
	while (((t_rooms *)er->content)->lvl != 0)
	{
		ln = findlist(((t_rooms *)er->content)->ln, er);
		cutpath(&ln, er);
		tmp = ft_lstnew((void *)(ln->content), (size_t)(sizeof(er)));
		ft_lstadd(&path, tmp);
		i++;
		path->content = (void *)ln->content;
		((t_rooms *)path->content)->vis2 = 1;
		if (i == 1)
			free(er);
		er = ln;
	}
	path->content_size = i;
	return (path);
}

void		alg(t_llrc *llrc)
{
	int		maxw;
	t_list	*last;
	t_list	*path;
	t_list	*paths;

	if (!(maxw = count_way(llrc)))
		return ;
	paths = NULL;
	while (llrc->psum < maxw)
	{
		if (!(last = bfs(llrc)))
			break ;
		path = buildpath(last);
		printflist(path);
		llrc->plensum += path->content_size;
		llrc->psum += 1;
		ft_listup(&paths, path);
		if (!paths->next && llrc->psum < maxw)
			continue;
		if (path_cmp2(llrc, path->content_size))//if true it didnt get better
		{
			break ;//run ant
		}
	/*	if (surb(&paths, llrc))
			break ;*/
	}
	if (paths)
		print_ant(&paths, llrc);
	ft_err();
}
