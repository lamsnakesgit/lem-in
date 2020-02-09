
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

void			ft_listup(t_list **alst, t_list *new)
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
