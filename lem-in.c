/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:13 by ddratini          #+#    #+#             */
/*   Updated: 2019/12/17 18:00:15 by ddratini         ###   ########.fr       */
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

unsigned int	amount_ants(int fd)
{
	char *line;

	if (get_next_line(fd, &line) > 0)
	{
		if (ft_atoi(line) == 0)// < 1
		{
			free(line);
			ft_err();
		}
		else
			ft_putendl(line);
		free(line);
	}
	else//free ?
		return (0);
	return (1);
}
/*char			**ft_split_room(char *line, char c)
{
	int i;
}*/
t_list			*ft_create_rooms(char *line)
{
	return (0);
}
/*
** if 1 line is ants_nums;
** * if not - or order or comment above ants -> display ERROR?
** * read next_line -> either "name_c-x_c-y" or "##start"/"##end"/"#"comment;
** if at least one space contained -> rooms mb; else -> check_##/start/end/commet#
** * then links: "name-1_name-2"
** //maybe written null in line?
** /submodeuls if u lno how to exec i will exec ,inflesliu
** actually delete putend; after- print_later
** also have to save fir-last rooms
** rooms: own gnl cycle : if comm/st/end slip; if st/end -> next? saveline
** else check_r-coords & save in lst
** - room that has no link?
*/
int				comstend(char *line)
{
	ft_putendl(line);//or after
	if (line[0] == '#' && line[1] == '#' && line && line + 1)
	{
		if (!ft_strcmp(line + 2, "start"))// || !ft_strcmp(line + 2, "end")) unlnowm coms ignoreD
		//else ft_err(); its a comm#
		//	ft_create_rooms();
			return (-1);
		if (!ft_strcmp(line + 2, "end"))
			return (-2);
	}
	else if (line[0] == '#')
		return (0);
	else
		return (1);
}
char				*room_save(char *line)
{
	char	**roomcor;
	int 	i;
	int		j;

	i = 0;
	roomcor = ft_strsplit(line, ' ');
	while (roomcor[i] && roomcor)
		++i;
	if (i == 3)
	{
		j = -1;
		while (roomcor[1][++j])
			if (!ft_isdigit(roomcor[1][j]))
				return (ft_err());
		j = -1;
		while (roomcor[2][++j])
			if (!ft_isdigit(roomcor[2][j]))
				return (ft_err());
	}
}
char				*check_room(char *line, int fd)
{//lineforma: "##start" "##end" "#comm" "nam1 cx cy"
	int		ret;
//if not comm-s -> saveline-checked; somee var to kkeep countrun on rooms->then link follow
	while (get_next_line(fd, line) > 0)
	{
		if ((ret = comstend(line)) == 0 || ret == -1 || ret == -2)
			continue ;
	/*	else if (ret == -1 || ret == -2)
		{	save 1/end		
		}*/
		else
		{//usual nemeroom w coords two//if (ft_strchr(line, ' '))//this maybe a room; save
			room_save(line);
		}
	}
	return (line);
}

int				val_in(int fd)
//char **av)
{
	char *line;

	if (amount_ants(fd) > 0)
	{//extra dop otd for chech_room w own w gnl
		//first--check_roomspresence_validif
			check_room(line, fd);
	}
	return (1);
}

int 			main(int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	if (ac > 1)// && fd > 0)//6)
		val_in(fd);//(ac, av);




















	return (0);
}
