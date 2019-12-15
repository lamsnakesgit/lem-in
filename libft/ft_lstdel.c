/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:47:50 by ddratini          #+#    #+#             */
/*   Updated: 2019/05/15 23:49:37 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmplink;
	t_list *chead;

	if (alst && del)
	{
		chead = *alst;
		while (chead)
		{
			tmplink = chead->next;
			del(chead->content, chead->content_size);
			free(chead);
			chead = tmplink;
		}
		*alst = NULL;
	}
}
