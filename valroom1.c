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

int			duplicheck(char **roomcor, t_llrc *lrc)
{
	t_list	*tmp;
	int		cmp;

	tmp = lrc->br;
	while (tmp)
	{
		if (!(ft_strcmp(((t_rooms *)(tmp->content))->name_r, roomcor[0])))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
