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
** if not - or order or comment above ants -> display ERROR?
** read next_line -> either "name_c-x_c-y" or "##start"/"##end"/"#"comment;
** then links: "name-1_name-2"
*/

int				val_in(int fd)
//char **av)
{
	char *line;

	if (amount_ants(fd) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (line && line[0] == '#');
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
