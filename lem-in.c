/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:13 by ddratini          #+#    #+#             */
/*   Updated: 2019/12/17 19:43:24 by ddratini         ###   ########.fr       */
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
t_rooms				*valroom_fill1(t_rooms *r, char **roomcor)
{
	
}
int					val_cord(char **roomcor)//ps related neg int?
{
	int		j;

	j = -1;
	while (roomcor[1][++j])
	{
		if (j == 10)
		if (!ft_isdigit(roomcor[1][j]) && ft_cleanmem(roomcor))
			return (ft_err());//0?
	}
	j = -1;
	while (roomcor[2][++j])
		if (!ft_isdigit(roomcor[2][j]) && ft_cleanmem(roomcor))
			return (ft_err());
	return (1);
}
/*
**send line ->check val inters->check coords; save r_name/room in linst;return->link1?
*/
t_rooms				*valroom_save(char *line)
{	char	**roomcor;
	int 	i;

	i = 0;
	roomcor = ft_strsplit(line, ' ');
	while (roomcor[i] && roomcor)
		++i;
	if (i == 3)
	{
		if (val_cord(roomcor))
			return (roomcor[0]);
		else
			return (0);
	}
	ft_cleanmem(roomcor);
	return (NULL);
}
/*t_rooms				*r_fill(t_rooms *r, char **roomcor)
{
	if (!roomcor)
	{
		;
	}
}*/
/*
**lineforma: "##start" "##end" "#comm" "nam1 cx cy"
//if not comm-s -> saveline-checked; somee var to kkeep countrun on rooms->then link follow
			{//usual nemeroom w coords two//if (ft_strchr(line, ' '))//this maybe a room; save
*/
char				*roomlinkblock(char *line, int fd)
{
	int		ret;
	char	*r_name;
	char	**roomcor;
	int 	i;
	t_list	*rr;
	t_rooms	*r;

	i = 0;
	r = r_fill(r, 0);
	while (get_next_line(fd, line) > 0 && ++i)
	{
		if ((ret = comstend(line)) == 0 || ret == -1 || ret == -2)
			continue ;
	/*	else if (ret == -1 || ret == -2)
		{	save 1/end
		}*/
		else
		{
			if (!(roomcor = valroom_save(line)))
				return (NULL);//thereis no room; or fault
			else
				valroom_fill1(r, roomcor);
		}
	}
	return (line);
}
/*
**{//extra dop otd for chech_room w own w gnl
** //first--check_roomspresence_validif
**next llevvell
block w rooms next links when 1 ends snptherstarts
	{
	}
*/
int				val_in(int fd)
{
	char *line;

	if (amount_ants(fd) > 0)
		roomlinkblock(line, fd);
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

	fd = open(av[1], O_RDONLY);
	if (ac > 1)// && fd > 0)//6)
		val_in(fd);//(ac, av);




















	return (0);
}
