/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:18:58 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/26 19:19:13 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** -llrc->psum
** llrc->plensum
*/

void		move_forth(t_llrc *llrc, t_list **path)
{
	if ((*path)->)

}
void		run_ants(t_llrc *llrc, t_list **path)
{
	int i;
	t_list *paths;
	int	psum;
	int plens;
	t_list *ln;

	i = 0;
	psum = 0;
	paths = (*path);
	printallpaths(paths);
	plens = 0;
	while (paths)
	{
		++psum;
		ln = paths->content;
		--plens;
		while (ln)
		{
			++plens;
			ln = ln->next;
		}
		printf("%d\n", plens);
		paths = paths->next;
	}
	paths = (*path);
	while (i < llrc->ants)
	{
		++i;
		if (((t_rooms *)paths->content)->ant == 0)
		{
			printf("L%d-%s", i, ((t_rooms*)paths->content)->name_r);
		}
	}
	return;
}
