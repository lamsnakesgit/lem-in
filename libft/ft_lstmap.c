/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:48:22 by ddratini          #+#    #+#             */
/*   Updated: 2019/05/15 23:48:41 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			*dele(t_list *sav)
{
	if (sav)
	{
		free(sav->content);
		free(sav);
		sav = NULL;
	}
	return (NULL);
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*sav;
	t_list			*mapped;
	t_list			*beg;

	if (!lst || !f)
		return (0);
	sav = f(lst);
	mapped = ft_lstnew(sav->content, sav->content_size);
	if (!mapped)
		return (0);
	beg = mapped;
	while (lst->next)
	{
		lst = lst->next;
		sav = f(lst);
		mapped->next = ft_lstnew(sav->content, sav->content_size);
		if (!mapped->next)
		{
			ft_lstdel(&beg, (void *)dele);
			return (NULL);
		}
		mapped = mapped->next;
	}
	return (beg);
}
