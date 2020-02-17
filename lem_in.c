/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:13 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/16 17:40:11 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** amount of ants - ints?
** unsigned int
*/

int					ft_err(void)
{
	write(1, "ERROR\n", 6);
	return (0);
}

t_llrc				nullst(t_llrc llrc)
{
	llrc.end = 0;
	llrc.st = 0;
	llrc.rmi = 0;
	llrc.br = 0;
	llrc.er = 0;
	llrc.arrrm = 0;
	llrc.plensum = 0;
	llrc.psum = 0;
	return (llrc);
}

void				freellrc(t_llrc *lrc)
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
**{//extra dop otd for chech_room w own w gnl
** //--check_roomspresence_validif
** if roomlinknlock -> error; free listrooms, contents
** if not valid links - free array of rooms, its contents, names, link lists
*/

long int			val_in(int fd, t_llrc *llrc)
{
	char	**ls;
	int		i;

	if (!(ls = processmap(fd, llrc)) || !(1 + ls))
		return (ft_err());
	*llrc = nullst(*llrc);
	i = roomlinkblock(ls + 1, llrc);
	if (!llrc->rmi || !i || llrc->end != 1 || llrc->st != 1)
	{
		return (freelrm(llrc) | free_map(ls) | ft_err());
	}
	if (!turninarr(llrc))
		return (0);
	if (ls && ls + i + 1)
	{
		if (!linkval(ls + i + 1, llrc))
		{
			return (delete_rooms(llrc, 0) | free_map(ls) | ft_err());
		}
	}
	free_map(ls);
	return (1);
}

int					main(int ac, char **av)
{
	int		fd;
	t_llrc	llrc;

	fd = 0;
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_40", O_RDONLY);
	if (val_in(fd, &llrc))
	{
		llrc.fl = 0;
		ft_printf("\n");
		if (ac > 1 && av[1])
		{
			ft_debug(av, &llrc);
		}
		alg(&llrc);
	}
	return (0);
}
