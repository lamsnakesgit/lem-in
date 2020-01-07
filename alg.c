/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:19:18 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/07 18:20:03 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 				print_l(t_llrc *lrc)
{
	t_list *l;
//	l = lrc->arrrm[rn[0]]->ln;
//	l = lrc->arrrm[13]->ln;
//	l = lrc->arrrm[1]->ln;
	int i = 0;
	l = lrc->arrrm[i]->ln;
	while (l)
	{
		while (l) {
			printf("i=%4s|%s\n", lrc->arrrm[i]->name_r,
				   ((t_rooms *) l->content)->name_r);//(t_rooms *)lrc->arrrm[rn[0]]->ln->content->name_r);
			//lrc->arrrm[rn[0]]->ln = lrc-
			l = l->next;
		}
//		printf("""");
		printf("\n");
		++i;
		if (!lrc->arrrm[i])
			break ;
		l = lrc->arrrm[i]->ln;
	}
}
/*
** delete links, rooms, ptr, name,
*/
void 			freee(t_llrc *llrc)
{
	llrc->
}
int				alg(t_llrc *llrc)
{
	int i;

	print_l(llrc);
	while (1)
	{
		break;
	}
	return 1;
}
