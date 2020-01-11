/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:18 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/06 16:18:49 by ddratini         ###   ########.fr       */
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
whet top stop on link-s?
*/

typedef struct s_rooms
{
	t_list          *rm;
	char	        *name_r;
	int		        x;
	int		        y;
	int 			vis;
	int 			lvl;
	int				nu;
//	struct s_rooms  *ln;
	t_list          *ln;
//	t_ 		links;
/*	struct s_rooms *next;
	{
	};
*/
	struct s_rooms  *next;
}				t_rooms;
//struct that contains ptr to list /arr w rooms & ptr to lins??
/*typedef	struct s_lemin
{
	long	nant;
	t_
}      			 t_lemin;*/
typedef struct s_link
{
	t_rooms         *rm;
	struct  s_link  *next;
}               t_link;
typedef struct s_llrc
{
       char    *linkd;
       t_list  *br;//roomnames;coords;addptrs
	   int		st;
	   int		end;
	   int		rmi;
	   t_rooms	*fr;
	   t_rooms	*er;
	   t_rooms	**arrrm;
	   int      ants;
}                              t_llrc;
int				iscomment(char *line);
int				rmorlink(char *line, t_llrc *llrc);//, t_list *rl);//0ptr-check

int				comstend(char *line);

char 			*linkval(char **line, t_llrc *lrc, int fd);
int         	corr_link(char **line, t_llrc *llrc, int *rn);//checkmarginindxs
int         	ispresent(t_llrc *llrc, char *rs);

int			    comstend(char *line);
t_list          *valroom_fill1(t_list **br, /*t_rooms *r,*/ char **roomcor);
int			    val_cord(char **roomcor);//ps related neg int?
char		    **valrmc_s(char *line);
int			    savemarg(t_llrc *lrc, int cm);//char *line,
int			    stcheck(char **line, t_llrc *lrc, int cm, int fd);
int             duplicheck(char **roomcor, t_llrc *lrc);
char		    *roomlinkblock(char **line, t_llrc *lrc, int fd);
void            turninarr(t_llrc *llrc);

int				ft_err(void);
unsigned int	amount_ants(int fd);

void 			print_l(t_llrc *lrc);

int				alg(t_llrc *llrc);

char			**lines(char *buf);
char			**processmap(int fd);


#endif
