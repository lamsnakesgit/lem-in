/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:18:58 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/07 18:56:44 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	printway(t_list *tr, t_llrc *llrc, int *ant, size_t *ul)
{
	if (!tr || ((t_rooms *)tr->content)->nu == llrc->er->nu)
		return ;
	else if (((t_rooms *)tr->next->content)->nu != llrc->er->nu)
		printway(tr->next, llrc, ant, ul);
	if (((t_rooms *)tr->content)->nu == llrc->fr->nu && *ul > 0)
	{
		llrc->er->vis += (((t_rooms *)tr->next->content)->nu == llrc->er->nu);
		*ul -= 1;
		(*ant)++;
		ft_printf("L%d-%s ", *ant, ((t_rooms *)tr->next->content)->name_r);
		((t_rooms *)tr->next->content)->ant = *ant;
	}
	if ((((t_rooms *)tr->next->content)->ant == 0 ||
		((t_rooms *)tr->next->content)->nu == llrc->er->nu) &&
		((t_rooms *)tr->content)->ant != 0)
	{
		llrc->er->vis += (((t_rooms *)tr->next->content)->nu == llrc->er->nu);
		ft_printf("L%d-%s ", ((t_rooms *)tr->content)->ant,
				((t_rooms *)tr->next->content)->name_r);
		((t_rooms *)tr->next->content)->ant = ((t_rooms *)tr->content)->ant;
		((t_rooms *)tr->content)->ant = 0;
	}
}

void	print_ant2(t_list **paths, t_llrc *llrc)
{
	t_list	*ln;
	t_list	*tr;
	int		ant;
	size_t	*ul;
	int		i;

	ant = 0;
	llrc->er->vis = 0;
	i = 0;
	while (llrc->er->vis < llrc->ants)
	{
		ln = *paths;
		while (ln)
		{
			tr = ln->content;
			ul = &ln->content_size;
			printway(tr, llrc, &ant, ul);
			ln = ln->next;
		}
		++i;
		ft_printf("\n");
	}
	ft_printf("I=%d\n", i);
}

void	print_ant(t_list **paths, t_llrc *llrc)
{
	t_list	*ln;
	int		i;
	int		s;

	ln = *paths;
	i = ((float)(llrc->plensum + llrc->ants)) / ((float)llrc->psum);
	s = 0;
	while (ln)
	{
	//	ft_printf("len = %d ", (int)((t_list *)ln->content)->content_size);
		ln->content_size = i - ((t_list *)ln->content)->content_size;
	//	ft_printf("ant = %d\n", (int)ln->content_size);
		s += ln->content_size;
		ln = ln->next;
	}
	i = (llrc->plensum + llrc->ants) - (i * llrc->psum);
	ln = *paths;
	while (i-- > 0)
	{
		ln->content_size += 1;
		ln = ln->next;
	}
	ft_printf("%d\n", (int)(*paths)->content_size);
	print_ant2(paths, llrc);
	del_paths(paths, llrc);
}
