/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:13 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/09 18:01:36 by ddratini         ###   ########.fr       */
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
*/

int					val_in(int fd, t_llrc *llrc)
{
	char	**ls;
	int		i;

	if (!(ls = processmap(fd, llrc)) || !(1 + ls))
		return (ft_err());
	*llrc = nullst(*llrc);
	i = roomlinkblock(ls + 1, llrc);
	if (!llrc->rmi || llrc->end != 1 || llrc->st != 1)
		return (ft_err());
	turninarr(llrc);
	if (ls && ls + i + 1)
	{
		if (!linkval(ls + i + 1, llrc))
		{
			free(llrc->er);
			free(llrc->fr);
			return (ft_err());
		}
	}
	free_map(ls);
	return (1);
}

int					main(void)
{
	int		fd;
	t_llrc	llrc;

	fd = 0;
	if (val_in(fd, &llrc))
	{
		printf("\n");
		alg(&llrc);
	}
	return (0);
}
