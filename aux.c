/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:19:14 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/25 15:19:23 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    ft_lstaddup(t_list **alst, t_list *new)
{
	t_list *alst2;
	if (*alst)
	{
		alst2 = *alst;
		while (alst2->next)
			alst2 = alst2->next;
		alst2->next = new;
		//while ((*alst)->next)
		//	*alst = (*alst)->next;
		//(*alst)->next = new;

//	new->next = NULL;
		//	*alst = alst2;
	}
	else
		*alst = new;
}

void				ft_lstnadd(t_list *ln, t_list *new)
{
	t_list *tmp;

	tmp = ln;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void    ft_lstadd_up(t_list **alst, t_list *new)
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

void crpath(t_list **path, t_list *tr)
{
	*path = ft_lstnew((void *)tr, (size_t)sizeof(*path));
	(*path)->content = tr->content;
	(*path)->content_size = tr->content_size;
//	(*path)->next = tr->next;
}

void    ft_listup(t_list **alst, t_list *new)
{
	t_list *alst2;
	if (*alst)
	{
		alst2 = *alst;
		while ((alst2)->next)
			alst2 = (alst2)->next;
		(alst2)->next = ft_lstnew((void *)new, (size_t)sizeof(new));
		(alst2)->next->content = new;
	}
	else
	{
		*alst = ft_lstnew((void *)new, (size_t)sizeof(new));
		(*alst)->content = new;
		(*alst)->next = NULL;
	}
}

void			unvisit(t_llrc *lrc)
{
	int i;

	i = -1;
	while (++i < lrc->rmi)
		lrc->arrrm[i]->vis = 0;
}
int 			*unvisited(int *vis, t_llrc *llrc)
{
	int i;

	i = -1;
	while (++i < llrc->rmi)//iter array
		vis[i] = 0;
	return (0);
}

void 				print_l(t_llrc *lrc)
{
	t_list *l;

	int i = 0;
	l = lrc->arrrm[i]->ln;
	while (l && i < lrc->rmi)
	{
		while (l)
		{
			printf("i=%4s|%6s=|%d\n", lrc->arrrm[i]->name_r,
				   ((t_rooms *) l->content)->name_r,
				   ((t_rooms *) l->content)->lvl);
			l = l->next;
		}
		printf("\n");
		++i;
		if (i == lrc->rmi)
			break ;
		l = lrc->arrrm[i]->ln;
	}
}

void			printflist(t_list *ln)
{
//	t_list *ln;
	t_list *path;
	int i = 0;

	path = ln;

	while (path)
	{
		printf("%s\n", ((t_rooms *)path->content)->name_r);
		path = path->next;
	}
}


int             count_way(t_llrc *llrc)
{
	int		min;
	t_list	*tf;
	t_list	*te;
	int 	f;

	tf = llrc->fr->ln;
	f = 0;
	while (tf)
	{
		++f;
		tf = tf->next;
	}
	min = llrc->ants > f ? f : llrc->ants;
	te = llrc->er->ln;
	f = 0;
	while (te)
	{
		++f;
		te = te->next;
	}
	min = min > f ? f : min;
	return (min);
}

int				clean(t_llrc *llrc, t_list **q)
{
	unvisit(llrc);
	if (!((*q) = ft_lstnew((const void *)llrc->fr, (size_t)(sizeof((void *)(llrc->fr))))))
		return 0;
	(*q)->content = (void *)llrc->fr;
//	((t_rooms *)(q->content))->lvl = 0;
	((t_rooms *)(*q)->content)->vis = 1;
	((t_rooms *)(*q)->content)->ant = -999;
	return (1);
}
