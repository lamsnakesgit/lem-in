/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:18 by ddratini          #+#    #+#             */
/*   Updated: 2019/12/17 17:08:02 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
#define LEMIN_H

#include <unistd.h> 
#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>
/*
**[ ] validation_map:
- [ ] # comment_start //in mid?
- [ ] Number of ants: only digits:in line //w out \n
- [ ] Ant_farm: blockkj:the_rooms: //aka name/ /c_x/ /x_y
- [ ]   ##start ->next_line = name/coord w 1
- [ ]   names separated by space; coords w space between; names/coords on margins
- [ ]   ##end -> name+coords w lastroom
- [ ]  block_2 the_lineks:
- [ ]   format: Name1-name2 
- 0 ants? 0 room?
** save during : line after n_A/start/end; until links-block s -1 start -2 end
*/
typedef struct s_rooms
{
	char	*name_r;
	int		x;
	int		y;
//	t_ 		links;
/*	struct s_rooms *next;
	{
	};
*/	
}				t_rooms;
//struct that contains ptr to list /arr w rooms & ptr to lins??
typedef	struct s_lemin
{
	long	nant;
	t_
}      			 t_lemin;

#endif
