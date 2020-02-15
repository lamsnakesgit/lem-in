/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:29:41 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/15 18:06:40 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					freermlst(t_llrc *llrc, t_rooms *rm)
{
	t_list *tmp;

	tmp = llrc->br;
	while (llrc->br)
	{
		tmp = llrc->br->next;
		free(((t_rooms *)llrc->br->content)->name_r);
		free(llrc->br->content);
		free(llrc->br);
		llrc->br = tmp;
	}
	free(rm->name_r);
	free(rm);
	return (0);
}

int					freelrm(t_llrc *llrc)
{
	t_list	*tmp;

	tmp = llrc->br;
	while (llrc->br)
	{
		tmp = llrc->br->next;
		free(((t_rooms *)llrc->br->content)->name_r);
		free(llrc->br->content);
		free(llrc->br);
		llrc->br = tmp;
	}
	return (0);
}
