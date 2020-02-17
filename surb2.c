/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surb2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:41:32 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/15 18:34:49 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	sur(t_mas *mas, t_llrc *llrc, t_list **paths)
{
	surb3(((t_list *)(*mas).tr->content)->next,
			((t_list *)(*mas).ln->content)->next, mas);
	(*mas).i += cross_path(paths, (t_list *)(*mas).m0, (t_list *)(*mas).m1, 0);
	(*mas).i += cross_path(paths, (t_list *)(*mas).m2, (t_list *)(*mas).m3, 1);
	llrc->plensum -= ((t_list *)(*mas).ln->content)->content_size;
	llrc->psum -= 1;
	delpath(paths, (*mas).ln, 0);
	if (!path_cmp(((t_list *)(*mas).tr->content)->content_size, llrc, (*mas).i))
	{
		(*mas).ln = lastpath(paths, 1);
		delpath(paths, (*mas).ln->next, 0);
		(*mas).ln->next = NULL;
		(*mas).ln = lastpath(paths, 1);
		delpath(paths, (*mas).ln->next, 0);
		(*mas).ln->next = NULL;
	}
	else
	{
		llrc->plensum += (*mas).i -
			((t_list *)(*mas).tr->content)->content_size;
		llrc->psum += 1;
		delpath(paths, (*mas).tr, 0);
	}
	(*mas).ln = lastpath(paths, 2);
	(*mas).tr = (*paths);
}

int		sur2(t_mas *mas, t_llrc *llrc, t_list **paths)
{
	if ((*mas).i == -1)
	{
		if (path_cmp2(llrc, ((t_list *)(*mas).ln2->content)->content_size))
		{
			llrc->psum -= 1;
			llrc->plensum -= ((t_list *)(*mas).ln2->content)->content_size;
			dellast(paths);
			return (1);
		}
	}
	return (0);
}

int		surb(t_list **paths, t_llrc *llrc)
{
	t_mas mas;

	mas.i = -1;
	mas.tr = (*paths);
	mas.ln = lastpath(paths, 0);
	mas.ln2 = mas.ln;
	if (mas.ln == mas.tr)
		return (0);
	while (mas.ln)
	{
		while (mas.tr->next && mas.tr != mas.ln)
		{
			if (surb2(((t_list *)mas.ln->content)->next,
						((t_list *)mas.tr->content)->next, &mas))
			{
				mas.i = 0;
				sur(&mas, llrc, paths);
				break ;
			}
			mas.tr = mas.tr->next;
		}
		mas.ln = mas.ln->next;
	}
	return (sur2(&mas, llrc, paths));
}
