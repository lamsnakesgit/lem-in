/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:05:20 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/25 16:05:28 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				surb2(t_list *ln, t_list *tr2, t_mas *mas)
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

void			surb3(t_list *ln, t_list *tr2, t_mas *mas)
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

int				cross_path(t_list **paths, t_list *ln, t_list *ln2, int f)
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

int				surb(t_list **paths, t_llrc *llrc)
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
			printallpaths(*paths);
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
			llrc->psum -= 1;
			llrc->plensum += ((t_list*)ln2->content)->content_size;
			delpath(paths, ln2);
			return (1);
		}
	}
	return (0);// if i = 0 то не пересек
}