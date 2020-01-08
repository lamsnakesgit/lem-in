/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:23:48 by ddratini          #+#    #+#             */
/*   Updated: 2020/01/06 16:23:50 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

unsigned int	amount_ants(int fd)
{
	char	*line;
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
	return (1);
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
			if ((rvl=rmorlink(*line, lrc))==2||!rvl)//orsavesep t_rm
				return 0;
			if (savemarg(lrc, cm) == 0)//*line,
				return 0000;//nonfree?/ret?
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

int				rmorlink(char *line, t_llrc *lrc)//, t_list *rl)
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
	else//check DUPS
	{
		if (lrc->br)
			if (!duplicheck(roomcor, lrc))
				return -2;
		lrc->br = valroom_fill1(/*&rl*/(&lrc->br), /*r,*/ roomcor);//vrf; llrc->br = rl;
		lrc->rmi++;
	}
	return 10;
}

char				*roomlinkblock(char **line, t_llrc *lrc, int fd)
{
	int		ret;
	int 	i;
	int		rm;
	char    **ok;//*->**

	i = 0;//r = r_fill(r, 0);
	while (get_next_line(fd, line) > 0 && ++i)//f returns line=*
	{
		if ((ret = comstend(*line))==0||ret==-3||ret==-1||ret==-2)
			free(*line);//repetiton of st/e/else?
		if (ret == -1 ||ret == -2)/*)//save1/rol/cycle.iscom*/
			if (!stcheck(line, lrc, ret, fd))//ret-check
				return (0);//fre?
		if (ret == 1)
		{
			if ((rm = rmorlink(*line, lrc)/*, (lrc->br))*/) == 2)
				return (*line);//if no rms->lnks(li);//
			free(*line);
			if (rm == 0 || rm == -2)
				return (0);
			ok = (char**)lrc->br->content;
			//	printf("%s\n|%s\n|%s\n", ((char**)lrc->br->content)[0], ((char**)(lrc->br->content))[1], ((char**)(lrc->br->content))[2]);
		}
	}
	return (0);//(*line);ERRvalrmonly
}
