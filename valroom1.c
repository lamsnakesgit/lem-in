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

int                 duplicheck(char **roomcor, t_llrc *lrc)
{//if all val recd-> atoi cors n check
	t_list *tmp;
	int     cmp;

	tmp = lrc->br;
	//while (lrc->br)
	while (tmp)
	{//char * void*[0]*
		//	if (!(ft_strcmp(((char**)(lrc->br->content))[0], roomcor[0])))
		if (!(ft_strcmp(((char**)(tmp->content))[0], roomcor[0])))
			return (0);
		cmp = ft_strcmp((((char**)(tmp->content))[1]), roomcor[1]);
		if (!(ft_strcmp((((char**)(tmp->content))[2]), roomcor[2])) && !cmp)
			return 0;
		//	lrc->br = lrc->br->next;
		tmp= tmp->next;
	}
	return (1);
}
