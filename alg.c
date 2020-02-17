/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:19:18 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/15 18:34:21 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** iterate through list of links to find out which link has a link to cur
** aka has link with content_size -1
** to go through that; lvl += cur lvl + 1; vis = 1; add to que particular room
*/

int			bft3(t_list *ln, t_list *cur, t_llrc *llrc)
{
	t_list *tr;

	if (((t_rooms *)ln->content)->vis2 == 1
			&& ln->content != llrc->fr
			&& ln->content != llrc->er)
	{
		tr = ((t_rooms *)ln->content)->ln;
		while (tr)
		{
			if (((t_rooms *)tr->content)->nu == ((t_rooms *)cur->content)->nu
					&& tr->content_size == (size_t)-1)
				return (1);
			tr = tr->next;
		}
	}
	return (0);
}

int			bft2(int *f, t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list *ln;

	ln = ((t_rooms *)cur->content)->ln;
	while (ln)
	{
		if (ln->content == llrc->fr || ln->content == llrc->er)
			*f = 1;
		if (bft3(ln, cur, llrc) && *f != 1)
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
			bft2(&f, cur, &q, llrc);
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

t_list		*buildpath(t_list *er, int i)
{
	t_list	*ln;
	t_list	*path;
	t_list	*tmp;

	if (!(path = ft_lstnew((void *)er, (size_t)sizeof(path))))
		return (0);
	path->content = er->content;
	path->next = 0;
	((t_rooms *)path->content)->vis2 = 1;
	while (((t_rooms *)er->content)->lvl != 0)
	{
		ln = findlist(((t_rooms *)er->content)->ln, er);
		cutpath(&ln, er);
		if (!(tmp = ft_lstnew((void *)(ln->content), (size_t)(sizeof(er)))))
			return (0);
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

	maxw = count_way(llrc);
	paths = NULL;
	while (llrc->psum < maxw)
	{
		if (!(last = bft(llrc)))
			break ;
		if (!(path = buildpath(last, 0)))
			break ;
		llrc->plensum += path->content_size;
		llrc->psum += 1;
		if (!(ft_listup(&paths, path)))
			break ;
		if (!paths->next && llrc->psum < maxw)
			continue;
		if (surb(&paths, llrc))
			break ;
	}
	if (!paths)
		ft_err();
	print_ant(&paths, llrc);
}
