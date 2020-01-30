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
/*t_list			*ft_create_rooms(char *line)
{   line+=0;
	return (0);
}*/

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
//	llrc->br =0;//uninit||init somethin?	llrc.fr = 0;
	llrc.er = 0;
	llrc.arrrm = 0;
	return (llrc);
}

void			freellrc(t_llrc *lrc)
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

int				val_in(int fd, t_llrc *llrc)
{
	char	*line;
	char	*linkd;
	char	**ls;
	int 	i;


	if (!(ls = processmap(fd, llrc)) || ! (1 + ls))
		return (ft_err());
//	if ((llrc->ants = amount_ants(fd)) < 1)//> 0)
//		return (ft_err());
	*llrc = nullst(*llrc);
	i = roomlinkblock(ls + 1, llrc, fd);//(&line, llrc, fd);//dupls?
	if (!llrc->rmi || llrc->end != 1 || llrc->st != 1)//i ?
		return (ft_err());//freel-ifl//free s/e
	turninarr(llrc);//(&llrc);
	if (ls && ls + i + 1)//1)//(linkd)//if freed? send rmlis+line+fd//st-end/line
	{
		//if (!linkval(&linkd, &llrc, fd))
		if (!linkval(ls + i + 1, llrc, fd))
		{
			free(llrc->er);
			free(llrc->fr);

//			ft_cleanmem(ls);
///			freellrc(llrc);
			return (ft_err());
		}
	}
	else
	{
		ft_cleanmem(ls);
		free(llrc->er);
		free(llrc->fr);
		freellrc(llrc);
		ft_err();
	}
	return (1);
}
/*
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
		else
			return -3;//
	}
	return (1);
}*/

int 			main(int ac, char **av)
{
	int fd;
	t_llrc llrc;

	ac += 0;//fd = open(av[1], O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map-42", O_RDONLY);
		   //maps_lemin/maps/map42", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map_42", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map-42", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map-42-dup", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/lem-in_rep/maps/map", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map_42", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/lem-in_rep/maps_lemin/maps/map20k-m", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/lem-in_rep/maps_lemin/maps/map38c", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/lem-in_rep/MAPGN", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/flow-one", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/flow-ten", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/flow-thousand", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/big", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/big-superposition", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mmap", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mapa2", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mapa3", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mapsd/valid/map_dead_end_3", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mapsd/valid/map_loop", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mapsd/valid/map_subject_3", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_comments", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_pdf", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_loop", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_shortest", O_RDONLY);
//	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/42_lem-in_tools/maps/valid/map_slack_2_brute", O_RDONLY);
	//fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/BIGSP", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mapsd/valid/map_dead_end_2", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/DIRlem-in_rep/mapsd/valid/map_pdf", O_RDONLY);
	//fd = 0;
	//if (ac > 1)// && fd > 0)//6)
	if (val_in(fd, &llrc))//(ac, av);
	{
		printf("\n");
		alg(&llrc);
//		alg_alt(&llrc);
	}
//	printl();
//	free(llrc.)
	return (0);
}
