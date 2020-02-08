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
Bfs: queue - root ; pop root-> putnbrs; mark levels path
-[ ] Create f node;
-[ ] Retrieve first out of q
-[ ] Check if its the end
-[ ] If non vis nor
-	 unvis links add to queue;
-	 Saving path in in;
create first node t_list *q; add f.r. -> q; q->next = 0;
while (q has els)
{pull1node; move ptr to beg node -> next;return the beg node
	while (curnode->links)
	{
 		add level to room mark;
 		add to prevlist of all pulled nodes to collect path;reverse
 		non vis lns -> add to que;
 		//while (curnode->ln)
 		//{curnode->ln->vis
 		//}
	}
}
 rmorlink dup else + 0.2
 sne darrlines to check ants/rms/cr/lns
 -qpush -qcreate
*/

typedef struct s_rooms
{
	t_list          *rm;
	char	        *name_r;
	int		        x;
	int		        y;
	int 			vis;
	int				vis2;
	int 			lvl;
	int				nu;
	int				ant;
	t_list          *ln;
}				t_rooms;
/*
** struct that contains ptr to list /arr w rooms & ptr to lins??
*/
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
	   long 	plensum;
	   long 	psum;
}                              t_llrc;
typedef	struct s_mas
{
	t_list *m0;
	t_list *m1;
	t_list *m2;
	t_list *m3;
}				t_mas;

int				iscomment(char *line);
int				rmorlink(char *line, t_llrc *llrc);//, t_list *rl);//0ptr-check
int				comstend(char *line);

char 			*linkval(char **line, t_llrc *lrc, int fd);

int         	corr_link(char **line, t_llrc *llrc, int *rn);//checkmarginindxs
int         	ispresent(t_llrc *llrc, char *rs);
int			    comstend(char *line);

t_list          *valroom_fill1(t_list **br, /*t_rooms *r,*/ char **roomcor, t_llrc *);
int			    val_cord(char **roomcor);//ps related neg int?
char		    **valrmc_s(char *line, t_llrc *llrc);
int			    savemarg(t_llrc *lrc, int cm);//char *line,
int			    stcheck(char **line, t_llrc *lrc, int cm, int fd);
int             duplicheck(char **roomcor, t_llrc *lrc);
int		    	roomlinkblock(char **line, t_llrc *lrc, int fd);
void            turninarr(t_llrc *llrc);
int				ft_err(void);

unsigned int	amount_ants(int fd);
void 			print_l(t_llrc *lrc);

int				alg(t_llrc *llrc);

char			**lines(char *buf);

char			**processmap(int fd, t_llrc *llrc);
int				alg_alt(t_llrc *llrc);

void			ft_listup(t_list **alst, t_list *new);
void			ft_lstadd_up(t_list **alst, t_list *new);

int 			queadd(t_list **q, t_list *tr);

t_list 			*pullnode(t_list **q);
t_rooms 		**queuefill(t_rooms **qu, t_llrc *llrc);
int 			quepush(t_llrc *llrc, t_list **q, t_list *tr);///push unvis nbrs

void			printflist(t_list *ln);

int             count_way(t_llrc *llrc);
int				clean(t_llrc *llrc, t_list **q);
void 			crpath(t_list **path, t_list *tr);

t_list 			*bfss(t_llrc *llrc);

void			printallpaths(t_list *ln);//paths)

int				surb(t_list **paths, t_llrc *llrc);

t_list			*lastpath(t_list **paths, int i);
int				path_cmp2(t_llrc *llrc, size_t len);
int				path_cmp(int last, t_llrc *llrc, int x);// if t > l то 1 путь лучше, чем 2 остальных
void			delpath(t_list **paths, t_list *ln);

void			run_ants(t_llrc *llrc, t_list **path);

void			sort_path(t_list **path);
void			print_ant(t_list **paths, t_llrc *llrc);

void			print_ant2(t_list **paths, t_llrc *llrc);

int 			quepush2(t_llrc *llrc, t_list **q, t_list *tr);//**tr)///push unvis nbrs

void			delete_rooms(t_llrc *llrc);

char			*ft_nstrsub(char const *s, unsigned int start, size_t len);
int 			issplitsp(char *s, char c);
int				validate(int ac, char **av, int i);

int				free_map(char **line);
int 			wrongroom(t_llrc *llrc, char **line, int f);
void			freermlst(t_llrc *llrc, t_rooms *rm);



#endif
