/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:32:48 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/09 17:07:37 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list		*pullnode(t_list **q)
{
	t_list	*h;

	h = 0;
	if (q && *q)
	{
		h = *q;
		(*q) = (*q)->next;
	}
	return (h);
}

int			quepush2(t_list **q, t_list *tr)
{
	t_list	*ln;
	int		i;

	ln = ((t_rooms *)((tr)->content))->ln;
	i = 0;
	while (ln)
	{
		if (((t_rooms *)(ln->content))->vis == 0
			&& ln->content_size != (size_t)-1)
		{
			((t_rooms *)ln->content)->lvl = ((t_rooms*)(tr)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ln);
		}
		ln = ln->next;
		++i;
	}
	return (0);
}

int			quepush3(t_list **q, t_list *tr)
{
	t_list	*ln;
	int		i;

	ln = ((t_rooms *)((tr)->content))->ln;
	i = 0;
	while (ln)
	{
		if (((t_rooms *)(ln->content))->vis == 0 && ((t_rooms *)ln->content)->vis2 == 0)
		//	&& ln->content_size != (size_t)-1)
		{
			((t_rooms *)ln->content)->lvl = ((t_rooms*)(tr)->content)->lvl + 1;
			((t_rooms *)ln->content)->vis = 1;
			queadd(q, ln);
		}
		ln = ln->next;
		++i;
	}
	return (0);
}

int			queadd(t_list **q, t_list *tr)
{
	t_list	*tmp;

	if (q && *q)
	{
		tmp = (*q);
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew((void *)tr->content, (size_t)sizeof(tr));
		tmp->next->content = (void *)tr->content;
	}
	else
	{
		(*q) = ft_lstnew((void *)tr->content, (size_t)sizeof(tr));
		(*q)->content = (void*)tr->content;
	}
	return (0);
}
