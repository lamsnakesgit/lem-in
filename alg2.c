/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:19:03 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/09 17:08:34 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		dellist(t_list *ln)
{
	t_list	*tr;

	while (ln)
	{
		tr = ln->next;
		free(ln);
		ln = tr;
	}
}

void		cutpath(t_list **er, t_list *er2)
{
	t_list	*ln;

	ln = ((t_rooms *)(*er)->content)->ln;
	while (ln)
	{
		if (((t_rooms *)(ln)->content) == ((t_rooms *)(er2->content)))
		{
			ln->content_size = -1;
			break ;
		}
		ln = ln->next;
	}
}

t_list		*findlist(t_list *ln, t_list *er)
{
	t_list	*tr;
	t_list	*cur;

	tr = NULL;
	cur = NULL;
	while (ln)
	{
		if (((t_rooms *)ln->content)->lvl ==
				((t_rooms *)er->content)->lvl - 1
				&& ((t_rooms *)ln->content)->vis2 == 1)
			tr = ln;
		if (((t_rooms *)ln->content)->lvl ==
				((t_rooms *)er->content)->lvl - 1
				&& ((t_rooms *)ln->content)->vis2 != 1)
			cur = ln;
		ln = ln->next;
	}
	return (cur != NULL ? cur : tr);
}

void		del_paths(t_list *path, t_llrc *llrc)
{
	t_list	*paths;
	t_list	*ln;
	t_list	*next;

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
