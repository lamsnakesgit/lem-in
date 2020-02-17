/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:05:20 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/07 18:52:06 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			surb2(t_list *ln, t_list *tr2, t_mas *mas)
{
	t_list	*ln2;
	t_list	*tr;
	int		l;

	ln2 = ln;
	l = 0;
	while (ln->next)
	{
		tr = tr2;
		while (tr)
		{
			if (tr->content == ln->content)
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

void		surb3(t_list *ln, t_list *tr2, t_mas *mas)
{
	t_list	*ln2;
	t_list	*tr;
	int		l;

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

int			cross_path(t_list **paths, t_list *ln, t_list *ln2, t_list *cur)
{
	t_list	*tr;
	t_list	*path;
	t_list	*main;
	int		i;

	i = 0;
	main = NULL;
	tr = cur;
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
