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
** assuming paths are located from the shortest to the longest
** move 1 ant to the first shortest path
** decide if to move 2 ant to the next path
** using formula: ants remain at the start
** and sum of differences between length of current path and lengths of shorter paths
**
*/
/*
void		move_forth(t_llrc *llrc, t_list **path)
{
	if ((*path)->)

}*/
/*
** iterate through lists & check if next->size is not less then cur->size
** save link of cur & next if else
** swap links
*/
void		swap_node(t_list **cur, t_list **ln, t_list **path)
{
	t_list *tr;
	t_list *paths;
	t_list *ln2;

	paths = (*path);
	tr = (*ln)->content;
	ln2 = (*ln)->content_size;
	(*ln)->content = (*cur)->content;
	(*ln)->content_size = (*cur)->content_size;
	(*cur)->content = tr->content;
	(*cur)->content_size = ln2;//tr->content_size;
/*	while (paths)
	{
		if (paths == *cur)

	}*/
}
void		sort_path(t_list **path)
{
	t_list *paths;
	t_list *cur;
	t_list *ln;

	paths = (*path);
//	while (paths)
//	{
	//	paths = (*path);
		while (paths)
		{
			if (paths->next && paths->content_size > paths->next->content_size)
			{
				swap_node(&paths, &paths->next, path);
				paths = (*path);
			}
			paths = paths->next;
		}
//		paths = (*path);
	///	paths = paths->next;
//	}
	paths = (*path);
//	printallpaths(paths);
}
void 		step(int ants, t_list **path)
{
	t_list *paths;

	paths = (*path);
}
/*
** move all ants to first room
** move ant in each path by iteration
** check all rooms in path
 * move
**
*/
void    printway(t_list *tr, t_llrc *llrc, int *ant, size_t *ul)
{
	if (!tr || ((t_rooms *)tr->content)->nu == llrc->er->nu)
		return;
	else if (((t_rooms *)tr->next->content)->nu != llrc->er->nu)
		printway(tr->next, llrc, ant, ul);
	if (((t_rooms *)tr->content)->nu == llrc->fr->nu && *ul > 0)
	{
		llrc->er->vis += (((t_rooms *)tr->next->content)->nu == llrc->er->nu);
		*ul -= 1;
		(*ant)++;
		printf("L%d-%s ", *ant, ((t_rooms *)tr->next->content)->name_r);
		((t_rooms *)tr->next->content)->ant = *ant;
	}
	if ((((t_rooms *)tr->next->content)->ant == 0 ||
	((t_rooms *)tr->next->content)->nu == llrc->er->nu) &&
	((t_rooms *)tr->content)->ant != 0)
	{
		llrc->er->vis += (((t_rooms *)tr->next->content)->nu == llrc->er->nu);
		printf("L%d-%s ", ((t_rooms *)tr->content)->ant,
			   ((t_rooms *)tr->next->content)->name_r);
		((t_rooms *)tr->next->content)->ant = ((t_rooms *)tr->content)->ant;
		((t_rooms *)tr->content)->ant = 0;
	}
}

void    print_ant2(t_list **paths, t_llrc *llrc)
{
	t_list * ln;
	t_list * tr;
	int ant;
	size_t *ul;
	int i;

	ant = 0;
	llrc->er->vis = 0;
	i = 0;
	while (llrc->er->vis < llrc->ants)
	{
		ln = *paths;
		while (ln)
		{
			tr = ln->content;//list
			ul = &ln->content_size;
			printway(tr, llrc, &ant, ul);
		//	printway(tr, llrc, &ant, ul);
			ln = ln->next;
		}
		++i;
		printf("\n");
	}
	printf("I=%d\n", i);
//	printf("END");
}

void                print_ant(t_list **paths, t_llrc *llrc)
{
	t_list * ln;
	int mas[llrc->psum];
	int i;
	int s;
	ln = *paths;
	i = 0;
	s = 0;
	while (ln)
	{
		mas[i] = (((t_list*)ln->content)->content_size * llrc->ants) / llrc->plensum;
		s += mas[i];
		ln = ln->next;
		i++;
	}
	mas[i - 1] += llrc->ants - s;
	ln = *paths;
//	printf("------\n");
	while (ln)
	{
		printf("----------\n%d\n---------\n", mas[i - 1]);
		ln->content_size = mas[--i];
		ln = ln->next;
	}
	print_ant2(paths, llrc);
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
