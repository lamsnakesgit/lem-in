/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:47:43 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/09 17:47:47 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_lstaddup(t_list **alst, t_list *new)
{
	t_list *alst2;

	if (*alst)
	{
		alst2 = *alst;
		while (alst2->next)
			alst2 = alst2->next;
		alst2->next = new;
	}
	else
		*alst = new;
}

void			ft_lstnadd(t_list *ln, t_list *new)
{
	t_list *tmp;

	tmp = ln;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int 			ft_listup(t_list **alst, t_list *new)
{
	t_list *alst2;

	if (*alst)
	{
		alst2 = *alst;
		while ((alst2)->next)
			alst2 = (alst2)->next;
		if (!((alst2)->next = ft_lstnew((void *)new, (size_t)sizeof(new))))
            return (0);
		(alst2)->next->content = new;
	}
	else
	{
		if (!(*alst = ft_lstnew((void *)new, (size_t)sizeof(new))))
		    return (0);
		(*alst)->content = new;
		(*alst)->next = NULL;
	}
    return (1);
}

void			ft_lstadd_up(t_list **alst, t_list *new)
{
	t_list *alst2;

	if (*alst)
	{
		alst2 = *alst;
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
		new->next = NULL;
		*alst = alst2;
	}
	else
		*alst = new;
}

void			crpath(t_list **path, t_list *tr)
{
	*path = ft_lstnew((void *)tr, (size_t)sizeof(*path));
	(*path)->content = tr->content;
	(*path)->content_size = tr->content_size;
}
