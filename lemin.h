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
	t_list *ln;
	t_list  *ln2;
	t_list  *tr;
	int     i;
}				t_mas;

int				surb2(t_list *ln, t_list *tr2, t_mas *mas);
void			surb3(t_list *ln, t_list *tr2, t_mas *mas);
int				cross_path(t_list **paths, t_list *ln, t_list *ln2, int f);
void    dellist(t_list	*ln);
void			cutpath(t_list **er,t_list *er2);
t_list 			*findlist(t_list *ln, t_list *er);
void            del_paths(t_list *path, t_llrc *llrc);
int				rmorlink(char *line, t_llrc *llrc);
int				comstend(char *line);
void		dellist(t_list *ln);
char 			*linkval(char **line, t_llrc *lrc, int fd);

int         	corr_link(char **line, t_llrc *llrc, int *rn);
int         	ispresent(t_llrc *llrc, char *rs);
int			    comstend(char *line);

t_list          *valroom_fill1(t_list **br,  char **roomcor);
int			    val_cord(char **roomcor);
char		    **valrmc_s(char *line);
int			    savemarg(t_llrc *lrc, int cm);
int			    stcheck(char **line, t_llrc *lrc, int cm, int fd);
int		    	roomlinkblock(char **line, t_llrc *lrc, int fd);
void            turninarr(t_llrc *llrc);
int				ft_err(void);

void				alg(t_llrc *llrc);

char			**lines(char *buf);

char			**processmap(int fd, t_llrc *llrc);

void			ft_listup(t_list **alst, t_list *new);
void			ft_lstadd_up(t_list **alst, t_list *new);

int 			queadd(t_list **q, t_list *tr);
int			quepush2(t_list **q, t_list *tr);
t_list 			*pullnode(t_list **q);
void			printflist(t_list *ln);

int             count_way(t_llrc *llrc);
int				clean(t_llrc *llrc, t_list **q);
void 			crpath(t_list **path, t_list *tr);

void			printallpaths(t_list *ln);

int				surb(t_list **paths, t_llrc *llrc);

t_list			*lastpath(t_list **paths, int i);
int				path_cmp2(t_llrc *llrc, size_t len);
int				path_cmp(int last, t_llrc *llrc, int x);
void			delpath(t_list **paths, t_list *ln);

void			print_ant(t_list **paths, t_llrc *llrc);

void			print_ant2(t_list **paths, t_llrc *llrc);

void			delete_rooms(t_llrc *llrc);



#endif
