/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:19:18 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/07 18:34:06 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			bft2(int *f, t_list *cur, t_list **q, t_llrc *llrc)
{
	t_list	*ln;

	ln = ((t_rooms *)cur->content)->ln;
	while (ln)
	{
		if (ln->content == llrc->fr || ln->content == llrc->er)
			*f = 1;
		if (((t_rooms *)ln->content)->vis2 == 1 && ln->content_size != -1
				&& ln->content != llrc->fr && ln->content != llrc->er && *f != 1)
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

	f = clean(llrc, &q);
	while (q != 0)
	{
		cur = pullnode(&q);
		(t_rooms *)((t_rooms *)cur->content)->ln->content;
		if (((t_rooms *)cur->content)->vis2 == 1
				&& ((t_rooms *)cur->content)->nu != llrc->er->nu
				&& ((t_rooms *)cur->content)->nu != llrc->fr->nu)
			bft2(&f, cur, &q, llrc);
		if (ft_strcmp(((t_rooms *)cur->content)->name_r,
				llrc->er->name_r) && f != 1)
			quepush2(&q, cur, llrc);
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
		if (!(last = bft(llrc)))
			break ;
		path = buildpath(last);
		printflist(path);
		llrc->plensum += path->content_size;
		llrc->psum += 1;
		ft_listup(&paths, path);
		if (!paths->next && llrc->psum < maxw)
			continue;
		if (surb(&paths, llrc))
			break ;
	}
	if (paths)
		print_ant(&paths, llrc);
	ft_err();
}
