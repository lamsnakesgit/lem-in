/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:18 by ddratini          #+#    #+#             */
/*   Updated: 2019/12/24 14:50:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
#define LEMIN_H
// 2147483647 - 2147483647?
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
if not comm/and -> check_r_save -> split = 3; 1/2 arrs[] = digitssole
when system call could not work?
##start
##end -->?
coords r strong ly strictli ints-> digits.10.max
level when rooms closed-finished?func bool
problems of rooms % links
rooms: ##st-nline
next line has to be? room_name1!
 ##end-nline #com - possible
	name x y
links: #com -> possible
	n1-n2//at least 1line
	also all rooms has to have links-be connectesd?
isroom funs - after ##commnds
VAL-PRCSS: duplicates??? rnames n coords????bonusesparteoos EOYEO
not/ebough link-etc
strct -ptrsonrmsc - lines;
allso common strct for all_tlstrms;rmcrs;st/end-separate ls/strcs;
when create arr-rms;etc?
rromlinkblock: line ** /to save whn apprch links/etc;ret-link-rm/cr
but free?ptr->strinl;
or zero-strct w lr-line; ptr
2 s/e? in links?
se-savesep-allstrct
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
/*typedef	struct s_lemin
{
	long	nant;
	t_
}      			 t_lemin;*/
typedef struct s_llrc
{
       char    *linkd;
       t_list  *br;//roomnames;coords;addptrs
}                              t_llrc;
int				iscomment(char *line);

#endif
