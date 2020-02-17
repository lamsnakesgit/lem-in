/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:26:03 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/17 17:33:20 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		dellast(t_list **paths)
{
	t_list	*ln;
	t_list	*tr;
	t_list	*next;
	t_list	*pre;

	ln = *paths;
	while (ln)
	{
		if (!ln->next)
		{
			tr = (t_list*)ln->content;
			while (tr)
			{
				next = (t_list *)tr->next;
				free(tr);
				tr = next;
			}
			free(ln);
			pre->next = 0;
			return;
		}
		pre = ln;
		ln = ln->next;
	}
}
