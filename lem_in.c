                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:13 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/29 18:49:12 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
/*
** amount of ants - ints?
** unsigned int
*/

int				ft_err(void)
{
	write(1, "ERROR\n", 6);
	return (0);
}

/*char			**ft_split_room(char *line, char c)
{
	int i;
}*/

t_llrc 			nullst(t_llrc llrc)
{
	llrc.end = 0;
	llrc.st = 0;
	llrc.rmi = 0;
	llrc.linkd = 0;
	llrc.br = 0;
	llrc.er = 0;
	llrc.arrrm = 0;
	llrc.psum = 0;
	llrc.plensum = 0;
	return (llrc);
}

void			freearr(t_llrc *lrc)
{
	int i;

	i = 0;
	while (i < lrc->rmi)
	{
		free(lrc->arrrm[i]);
		++i;
	}
	free(lrc->arrrm);
}

/*
** go through lst if f == x delete x; names/contents/links
** when do we delete list of rooms?
** first cycle = list of rooms
** second array or fooms +- links
*/
int 			free_array_content(t_llrc *llrc, char **line, int f)
{
	int i;

	i = 0;
	while (++i < llrc->rmi)
	{
		//	free(llrc->arrrm[i]->name_r);
		while (llrc->arrrm[i]->ln)
		{
			tmp = llrc->arrrm[i]->ln->next;
			free(llrc->arrrm[i]->ln);
			llrc->arrrm[i]->ln = tmp;
		}
		free(llrc->arrrm[i]->name_r);
		free(llrc->arrrm[i]);
	}
	free(llrc->arrrm);
}
int 			wrongroom(t_llrc *llrc, char **line, int f)
{
	int i;
	t_list	*tmp;

	while (llrc->br)
	{
		tmp = llrc->br->next;
		free(((t_rooms *)llrc->br->content)->name_r);
		free((t_rooms *)llrc->br->content);
		free(llrc->br);
		llrc->br = tmp;
	}
	i = -1;
	if (f == 2)
	{
		free_array_content(llrc, line, f);
	}
	free(line[0]);
	free(line);
	return (1);
}
/*
**{//extra dop otd for chech_room w own w gnl
** //--check_roomspresence_validif
** i == 0 -> no links or else error
*/

int				val_in(int fd, t_llrc *llrc)
{
	char	*line;
	char	*linkd;
	char	**ls;
	int 	i;

	if (!(ls = processmap(fd, llrc)) || ! (1 + ls))
		return (ft_err());
	*llrc = nullst(*llrc);
	i = roomlinkblock(ls + 1, llrc, fd);
	if (!llrc->rmi || llrc->end != 1 || llrc->st != 1 || !i)
	{
		wrongroom(llrc, ls, 1);
		return (ft_err());
	}
	turninarr(llrc);
	if (ls + i + 1)
		if (!linkval(ls + i + 1, llrc, fd))
		{
			wrongroom(llrc, ls, 2);
			return (ft_err());
		}
	free_map(ls);
	return (1);
}

int 			main(int ac, char **av)
{
	int fd;
	t_llrc llrc;

	fd = open("/Users/gusujio/lem-in/42_lem-in_tools/maps/valid/big_sup/map_big_sup_1", O_RDONLY);
	fd = open("/Users/gusujio/lem-in/42_lem-in_tools/maps/valid/map_39", O_RDONLY);
    //fd = open("/Users/gusujio/lem-in/42_lem-in_tools/maps/valid/big/map_big_1", O_RDONLY);invalid/ants_empty
//	fd = open("/Users/ddratini/42_03_projests/lem-in/42_lem-in_tools/maps/valid/map_25" ,O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_25", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_simple", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/map_42", O_RDONLY);
    ///Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/invalid/empty_map", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/invalid/room_name_duplicated", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/invalid/ants_nbr_too_big", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_invalidcommand1", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/nolinksb", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/emptyline", O_RDONLY);
//	fd = 0;
	if (val_in(fd, &llrc))//(ac, av);
	{
		ft_putstr("\n");
		alg(&llrc);
	}
	return (0);
}
