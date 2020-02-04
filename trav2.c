/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trav2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:35:41 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/04 19:35:43 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

long 					follow_each_path(long steps, t_list *path, t_llrc *llrc)
{
	t_list *paths;
	long 	ants;

	ants = llrc->ants;
	paths = path;
	while (paths)
	{
		paths->flow = 0;
		paths = paths->next;
	}
	paths = path;
	while (steps > 0)
	{
		paths = path;
		while (paths)// && ants > 0)
		{
			if (steps > ((t_list *)paths->content)->content_size)//paths->content_size)
			{
				++paths->flow;
				--ants;
			}
			paths = paths->next;
		}
		/*	if (steps <= ((t_list *)path->content)->content_size)//path->content_size)//(ants <= path->content_size)
			{
				while (ants > 0)//steps > 2)
				{
					++path->flow;
					--ants;
					--steps;
				}
			}
		*/	--steps;
	}
/*	while (ants)
	{
		paths = path;
		while (paths)
		{
			if (steps > ((t_list *)path->content)->content_size)
			{
				++paths->flow;
				--ants;
			//	--steps;
			}
			paths = paths->next;
		}
		if (steps <= ((t_list *)path->content)->content_size)//if steps less minpathlen
		{
			++path->flow;
			--ants;
			--steps;
		}
		--steps;
	}*/
	paths = path;
	while (paths)
	{
		paths->content_size = paths->flow;
		printf("ANTS=%ld CSIZE=%ld ", paths->flow, paths->content_size);
		paths = paths->next;
	} printf("\n");
	return (0);
}
long int				count_steps(t_llrc *llrc, t_list *path)
{
	long	steps;
	t_list	*paths;
	long	lenp;
	long 	rev;
	long 	nonrev;
	long 	rema;
	long	flow;
	long 	newrev;
	long 	nupath;
	int i = 0;
	t_list *pat;

	pat = path;
//	while (path)
//	{
	/*	path->content_size = 2;
		if (path->next)
		{
			path->next->content_size = 5;
			if (path->next->next)
				path->next->next->content_size = 10;
		}*/
//	}

	paths = path;
	lenp = ((t_list *)paths->content)->content_size;//paths->content_size;
	rema = 0;
	flow = 1;//0;
	nupath = 1;
	steps = llrc->ants + lenp - 1;
	while (paths)// && i < 3)
	{
		if (paths->next)
		{
			//		steps = llrc->ants + paths->next->content_size - 1;//shortest path - flow-cap
			if (steps > ((t_list *)paths->next->content)->content_size)
				//paths->next->content_size)//paths)//->next->content_size)
			{
				rev = steps - (((t_list *)paths->next->content)->content_size - 1);
				//steps - (paths->next->content_size - 1);
				nonrev = steps - rev;
			}
			else
				break ;
			rema = ((rev * nupath) + rema) % ++flow;
			newrev = ((rev * nupath) + rema) / flow;
			steps = newrev + rema + nonrev;
		}
		paths = paths->next;
		++nupath;
		++i;
	}
	printf("STEPS=%ld\n", steps);
	return (steps);
}
