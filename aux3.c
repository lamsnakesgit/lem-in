/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:26:03 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/17 17:33:20 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		dellast(t_list **paths)
{
	t_list	*ln;
	t_list	*tr;
	t_list	*next;
	t_list	*pre;

	ln = *paths;
	while (ln)
	{
		if (!ln->next)
		{
			tr = (t_list*)ln->content;
			while (tr)
			{
				next = (t_list *)tr->next;
				free(tr);
				tr = next;
			}
			free(ln);
			pre->next = 0;
			return ;
		}
		pre = ln;
		ln = ln->next;
	}
}

int			compareway(t_list *ln, t_list *tr)
{
	while (ln)
	{
		if (((t_rooms *)ln->content)->nu != ((t_rooms *)tr->content)->nu)
			return (1);
		ln = ln->next;
		tr = tr->next;
	}
	return (0);
}

void		ft_debug(char **av, t_llrc *llrc)
{
	int i;

	i = 0;
	if (av[1][0] == '-' && av[1][1] == 'a' && !av[1][2])
		llrc->fl = 1;
}
