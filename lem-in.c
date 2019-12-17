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
		if (ft_atoi(line) == 0)
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
*/
int				check_room(char *line)
{//lineforma: "##start" "##end" "#comm" "nam1 cx cy"
	if (line[0] == '#' && line[1] == '#' && line && line + 1)
	{
		if (!ft_strcmp(line + 2, "start") || !ft_strcmp(line + 2, "end"))
			ft_putendl(line);//else ft_err(); its a comm#
	}
	else if (line[0] == '#')//mb shorter lines
		ft_putendl(line);//return (1);
	else
	{//usual nemeroom w coords two
		if (ft_strchr(line, ' '))
	}
	return (0);
}

int				val_in(int fd)
//char **av)
{
	char *line;

	if (amount_ants(fd) > 0)
	{//extra dop otd funs for chech_room w own w gnl
		while (get_next_line(fd, &line) > 0)
		{//first--check_roomspresence_validif
		//	if (ft_strchr(line, ' '))
				check_room(line);
			//if (line && line[0] == '#')
			//	;
		}
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
