/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valroom1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:28:53 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/07 18:29:26 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** //if all val recd-> atoi cors n check
*/

int					duplicheck(char **roomcor, t_llrc *lrc)
{
	t_list	*tmp;

	tmp = lrc->br;
	while (tmp)
	{
		if (!(ft_strcmp(((t_rooms *)(tmp->content))->name_r, roomcor[0])))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int					copyse(t_llrc *llrc)
{
	int i;

	i = 0;
	while (i < llrc->rmi)
	{
		if (!ft_strcmp(llrc->arrrm[i]->name_r, llrc->fr->name_r))
			llrc->fr->ln = llrc->arrrm[i]->ln;
		else if (!ft_strcmp(llrc->arrrm[i]->name_r, llrc->er->name_r))
			llrc->er->ln = llrc->arrrm[i]->ln;
		++i;
	}
	while (i < llrc->rmi)
	{
		if (llrc->arrrm[i]->nu == llrc->fr->nu)
			llrc->fr->ln = llrc->arrrm[i]->ln;
		else if (llrc->arrrm[i]->nu == llrc->er->nu)
			llrc->er->ln = llrc->arrrm[i]->ln;
	}
	return (1);
}

int					ispresent(t_llrc *llrc, char *rs)
{
	int		i;

	i = 0;
	while (i < llrc->rmi)
	{
		if (ft_strcmp(llrc->arrrm[i]->name_r, rs) == 0)
		{
			free(rs);
			return (i);
		}
		++i;
	}
	free(rs);
	return (-1);
}
