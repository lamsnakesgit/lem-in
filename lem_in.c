/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:13 by ddratini          #+#    #+#             */
/*   Updated: 2019/12/30 17:30:42 by ddratini         ###   ########.fr       */
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
t_list			*ft_create_rooms(char *line)
{   line+=0;
	return (0);
}

t_rooms				*r_fill(t_rooms *r, char **roomcor)
{
	if (!r)//!roomcor)
	{
	//	r = ()
		r->name_r = roomcor[0];
		r->x = ft_atoi(roomcor[1]);
		r->y = ft_atoi(roomcor[2]);
	}
	return (r);
}

t_llrc 			nullst(t_llrc llrc)
{
	llrc.end = 0;
	llrc.st = 0;
	llrc.rmi = 0;
	llrc.linkd = 0;
	llrc.br = 0;//rl=0?
	llrc.fr = 0;
	llrc.er = 0;
	llrc.arrrm = 0;
	return (llrc);
}

/*
**{//extra dop otd for chech_room w own w gnl
** //--check_roomspresence_validif
*/

int				val_in(int fd)
{
	char	*line;
	char	*linkd;
	t_llrc	llrc;

	if ((llrc.ants = amount_ants(fd)) < 1)//> 0)
		return (ft_err());
	llrc.br =0;//uninit||init somethin?
	llrc = nullst(llrc);
	linkd = roomlinkblock(&line, &llrc, fd);//dupls?
	if (!llrc.rmi || llrc.end != 1 || llrc.st != 1)
		return (ft_err());//freel-ifl//free s/e
	turninarr(&llrc);
	if (linkd)//if freed? send rmlis+line+fd//st-end/line
	{
		if (!linkval(&linkd, &llrc, fd))
			return (ft_err());
	}
	else
		ft_err();
	return (1);
}

int				iscomment(char *line)
{
	if (line[0] == '#')
	{
		if (line[1] != '#' && line[1])
			return (0);
		if (ft_strcmp(line + 2, "start"))
			return (-1);
		if (ft_strcmp(line + 2, "end"))
			return (-2);
	}
	return (1);
}

int 			main(int ac, char **av)
{
	int fd;

	ac += 0;
	fd = open(av[1], O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map-42", O_RDONLY);
		   //maps_lemin/maps/map42", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map_42", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map-42", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map-42-dup", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/maps/map", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map_l", O_RDONLY);
	//if (ac > 1)// && fd > 0)//6)
		val_in(fd);//(ac, av);
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
	return (0);
}
