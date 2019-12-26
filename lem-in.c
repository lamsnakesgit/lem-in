/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:42:13 by ddratini          #+#    #+#             */
/*   Updated: 2019/12/26 18:19:02 by ddratini         ###   ########.fr       */
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
	int 	nant;

	if (get_next_line(fd, &line) > 0)
	{
		if ((nant = ft_atoi(line)) == 0)// < 1
		{
			free(line);
			return (0);//(ft_err());
		}
		else
		{
		    ft_putendl(line);
		    free(line);
        //    return (0);
        }
	}
	else//free ?
		return (0);
	return (nant);
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
** if not - or order or comment above ants -> display ERROR?
** read next_line -> either "name_c-x_c-y" or "##start"/"##end"/"#"comment;
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
		else
			return (-3);//commnd?
	}
	else if (line[0] == '#')
		return (0);
	else
		return (1);
	return (-34);
}
/*t_rooms				*/
t_list              *valroom_fill1(t_list **br, /*t_rooms *r,*/ char **roomcor)
{
	if (!br || !*br)
	{
		*br = ft_lstnew((const void *)roomcor, (size_t)sizeof(roomcor));
		(*br)->content = (void *)roomcor;
        return (*br);
	}
	else
	{
	//	br = br->next;
		ft_lstadd(br, ft_lstnew((const void *)roomcor, (size_t)sizeof(roomcor)));//br);
		return (*br);
	}
    return (0);
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
** delete- if nonval rmcor
*/
/*t_rooms				*/
char				**valrmc_s(char *line)
{	char	**roomcor;
	int 	i;

	i = 0;
	if (!(roomcor = ft_strsplit(line, ' ')))
		return 0;
	while (roomcor[i] && roomcor)
		++i;
	if (i == 3 && roomcor[0][0] != 'L' && val_cord(roomcor))
		return (roomcor);
	ft_cleanmem(roomcor);
	return (NULL);
}
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

/*
 ** line - contains no room/!' '/'-'/ mb linked roomsnames
 ** we now have to check rooms presence in all linkes
 ** duplicate names?
 */
char 				*linkval(char **line, t_llrc *llrc, int fd)
{
	int ret;

	while (get_next_line(fd, line) > 0)
	{
		if ((ret = comstend(*line))==0||ret==-3)
			free (*line);
		else if (ret == -2 || ret == -1)
			return (0);
	}
	return (0);
}
int					savemarg(char *line, t_llrc *lrc, int cm)
{
	t_rooms *x;
	char	**roomcor;
	int		i;
	char 	**ok;
	i = 0;//lastcalfunck
	ok = (char**)lrc->br->content;//???	//ok = (char**)lrc->br->content;
	printf("%s\n%s\n%s\n", ok[0], ok[1], ok[2]);
	//x->x = 0;
	x = (t_rooms*)malloc(sizeof(t_rooms));
	x->name_r = 0; x->x = 0-1; x->y = -1;
//	x->name_r = lrc->br->content;//-
//	x->name_r = ((char*)lrc->br->content)[0];//-
	x->name_r = ok[0];
	x->x = ft_atoi(ok[1]);
	x->y = ft_atoi(ok[2]);
//	x->x = lrc->br->content[1];
//	roomcor = ft_strsplit(line, ' ');//dont we ned to pnt-1lst?
//	x->y = ft_atoi(roomcor[2]);//malloc??x//rfil!!!
	if (cm == -1)
		lrc->fr = x;
	if (cm == -2)
		lrc->er = x;
	return -11;
}
int					stcheck(char **line, t_llrc *lrc, int cm, int fd)
{
	int re;
	int rvl;
//	if (cm == -2)++lrc->end;if (cm == -1)++lrc->st;
	cm == -2 ? ++lrc->end : ++lrc->st;
	if (lrc->st > 1 || lrc->end > 1)
		return 0;
	while (get_next_line(fd, line) > 0)
	{
		if ((re=comstend(*line))!=1)
		{
			free(*line);
			if (re ==-2||re==-1)
				return 0;
		}
		else if (re == 1)
		{//freelst?
			if ((rvl=rmorlink(*line, lrc, lrc->br))==2||!rvl)
			//orsavesep t_rm
				return 0;
			savemarg(*line, lrc, cm);//nonfree?/ret?
			free (*line);
			return 1;
		}//cont aft -1/-2 exit?
	}
	return 0;
}
/*
**lineforma: "##start" "##end" "#comm" "nam1 cx cy"
//if not comm-s -> saveline-checked; somee var to kkeep countrun on rooms->then link follow
			{//usual nemeroom w coords two//if (ft_strchr(line, ' '))//this maybe a room; save
	add counter of st & en in cylcle; check st-|end end-|st
	save rooms; after val-r-x-y; in lists ptr to 1 placeh mem/2d-arrs
	if valrmcor->ssave links
	check if linksblck? how->nextstep?
	!' ' -> no rooms-coors
 	i guess create seprt roomspace for s/e;ret=line+strct w roomptr
*/
/*
** comms -skipped;counted;nost/e->fail;no after s/e/-?F;if rm if link
** //mb link->sendline; inval-rmc???ret
**		//ret if links->?in here->save-vallink
*/
int				rmorlink(char *line, t_llrc *llrc, t_list *rl)
{
	char	**roomcor;

	if (!ft_strchr(line, ' '))//btwr-name-1//lol/KO
	{//oi	free (line);//0?
	//	return(line);//line == 0 ? return (0) : return (llrc);//.linkd = line);
		return 2;
	}
	if (!(roomcor = valrmc_s(line)))//STOP
		return (0);//(NULL);//thereis no room; or fault
	//if (ft_strchr))
	else
	{
		llrc->br = valroom_fill1(/*&rl*/(&llrc->br), /*r,*/ roomcor);//vrf; llrc->br = rl;
		llrc->rmi++;
	}
	return 10;
}
char				*roomlinkblock(char **line, t_llrc *llrc, int fd)
{
	int		ret;
	int 	i;
	int		rm;

	i = 0;//r = r_fill(r, 0);
	while (get_next_line(fd, line) > 0 && ++i)
	{//comms are skipped all throughout thw block
		if ((ret = comstend(*line))==0||ret==-3||ret==-1||ret==-2)
			free(*line);//repetiton of st/e/else?
		if (ret == -1 ||ret == -2)/*)//save1/rol/cycle.iscom*/
			if (!stcheck(line, llrc, ret, fd))//ret-check
				return (0);//fre?
		if (ret == 1)
		{///*llrc.linkd =*/ rmorlink(*line, &llrc,&(llrc.br));
			//&rl);
		//	if (line)//(llrc.linkd)//li)//hr->funlink?;?stopplace4rmsN0
			if ((rm = rmorlink(*line, llrc, (llrc->br))) == 2)	
				return (*line);//if no rms->lnks(li);//
			free(*line);
			if (rm == 0)
				return (0);
		}
	}
	return (0);//(*line);ERRvalrmonly
}
t_llrc 			nullst(t_llrc llrc)
{
	llrc.end = 0;
	llrc.st = 0;
	llrc.rmi = 0;
	llrc.linkd = 0;
	llrc.br = 0;//rl=0?
	llrc.fr = 0;
	llrc.er = 0;
	llrc.arrrm = 0;
	return (llrc);
}
/*
**{//extra dop otd for chech_room w own w gnl
** //--check_roomspresence_validif
*/

int				val_in(int fd)
{
	char	*line;
	char	*linkd;
	t_llrc	llrc;

	if (amount_ants(fd) > 0)
	{
		llrc = nullst(llrc);
		linkd = roomlinkblock(&line, &llrc, fd);//dupls?
		if (!llrc.rmi || llrc.end != 1 || llrc.st != 1)
			return (ft_err());//freel-ifl//free s/e
		if (linkd)//if freed? send rmlis+line+fd//st-end/line
			linkval(&linkd, &llrc, fd);
		else
			ft_err();
	}
	else
		ft_err();
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
//	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map-42", O_RDONLY);
		   //maps_lemin/maps/map42", O_RDONLY);
	fd = open("/Users/ddratini/42_03_projests/lem-in_rep/map_42", O_RDONLY);
	if (ac > 1)// && fd > 0)//6)
		val_in(fd);//(ac, av);
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
	return (0);
}
