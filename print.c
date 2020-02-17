/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:47:17 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/17 16:05:21 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_l(t_llrc *lrc)
{
	t_list	*l;
	int		i;

	i = 0;
	l = lrc->arrrm[i]->ln;
	while (l && i < lrc->rmi)
	{
		while (l)
		{
			ft_printf("i=%4s|%6s=|%d\n", lrc->arrrm[i]->name_r,
				((t_rooms *)l->content)->name_r,
				((t_rooms *)l->content)->lvl);
			l = l->next;
		}
		ft_printf("\n");
		++i;
		if (i == lrc->rmi)
			break ;
		l = lrc->arrrm[i]->ln;
	}
}

void			printflist(t_list *ln)
{
	t_list	*path;
	int		i;

	i = 0;
	path = ln;
	while (path)
	{
		if (!path->content)
			ft_printf("(!path->content)\n");
		else
			ft_printf("%s ", ((t_rooms *)path->content)->name_r);
		path = path->next;
	}
	ft_printf("\n");
}

void			printallpaths(t_list *ln)
{
	t_list *path;

	path = ln;
	while (path)
	{
		printflist(path->content);
		path = path->next;
	}
	ft_printf("\n");
}

t_list			*lastpath(t_list **paths, int i)
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

void			delpath(t_list **paths, t_list *ln, t_list *tr2)
{
	t_list *tr;

	tr = *paths;
	tr2 = NULL;
	while (tr)
	{
		if (tr == ln) //if (!compareway(tr->content, ln->content))
		{
			if (!tr2)
				(*paths) = (*paths)->next;
			else
				tr2->next = ln->next;
			dellist(ln->content);
			free(ln);
			return ;
		}
		tr2 = tr;
		tr = tr->next;
	}
}
