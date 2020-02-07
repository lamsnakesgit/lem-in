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
		printf("%s ", ((t_rooms *)path->content)->name_r);
		path = path->next;
	}
	printf("\n");
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
	int i;

	if (!((*q) = ft_lstnew((const void *)llrc->fr, (size_t)(sizeof((void *)(llrc->fr))))))
		return 0;
	i = -1;
	while (++i < llrc->rmi)
	{
		llrc->arrrm[i]->vis = 0;
		llrc->arrrm[i]->lvl = 0;
	}
	(*q)->content = (void *)llrc->fr;
	((t_rooms *)(*q)->content)->vis = 1;
	((t_rooms *)(*q)->content)->ant = 0;
	return (0);
}

void		printallpaths(t_list *ln)//paths)
{
	t_list *path;

	path = ln;
	while (path)
	{
		printflist(path->content);
		path = path->next;
	}
	printf("\n");
}

t_list *lastpath(t_list **paths, int i)
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


int				path_cmp2(t_llrc *llrc, size_t len)
{
	float l;
	float t;

	if (llrc->psum == 1)
		return 1;
	l = ((float)llrc->ants + (float)llrc->plensum) / (float)llrc->psum;// с новым
	t = ((float)llrc->ants + (float)llrc->plensum - (float)len) / ((float)llrc->psum - 1);
	return (l >= t);//if t >= l -> break
}

int    path_cmp(int last, t_llrc *llrc, int x)// if t > l то 1 путь лучше, чем 2 остальных
{
	float t;
	float l;

	l = (float)(llrc->ants + llrc->plensum - last + x) / (float)(llrc->psum + 1);
	t = (float)(llrc->ants + llrc->plensum) / (float)llrc->psum;

	return (t > l);
}

void 	delpath(t_list **paths, t_list *ln)
{
	t_list *tr;
	t_list *tr2;

	tr = *paths;
	tr2 = NULL;
	while (tr)
	{
		if (tr == ln)
		{
			if (!tr2)
			{
				(*paths) = (*paths)->next;
				free(tr);
			}
			else
			{
				tr2->next = ln->next;
				free(ln);
			}
			return ;
		}
		tr2 = tr;
		tr = tr->next;
	}
}

void	delete_rooms(t_llrc *llrc)
{
	int i;
	t_list *tmpbr;
	t_list *nextbr;
	t_list  *tmp;

	i = 0;
//	free(llrc->er);
//	free(llrc->fr);
	while (i < llrc->rmi)
	{
		free(llrc->arrrm[i]->name_r);
		while (llrc->arrrm[i]->ln)
		{
			tmp = llrc->arrrm[i]->ln->next;
			free(llrc->arrrm[i]->ln);
			llrc->arrrm[i]->ln = tmp;
		}
		free(llrc->arrrm[i]);
		++i;
	}
	tmpbr = llrc->br;
	while (tmpbr)
	{
		nextbr = tmpbr->next;
		free(tmpbr);//->next)
		tmpbr = nextbr;
	}
	free(llrc->arrrm);
}