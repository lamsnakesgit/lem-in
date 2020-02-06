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
	int i;
//	if (cm == -2)++lrc->end;if (cm == -1)++lrc->st;

	i = 0;
	cm == -2 ? ++lrc->end : ++lrc->st;
	if (lrc->st > 1 || lrc->end > 1)
		return -2;
	while (line[i])//(get_next_line(fd, line) > 0)
	{
		if ((re=comstend(line[i]))!=1)
		{//	free(*line);
			if (re ==-2||re==-1)
				return -2;
		}
		else if (re == 1)
		{//freelst?
			if ((rvl=rmorlink(line[i], lrc))==2||!rvl)//orsavesep t_rm
				return -2;//0;
			if (savemarg(lrc, cm) == 0)//*line,
				return -2;//0000;//nonfree?/ret?
		//	free (*line);
			return (1 + i);//1;
		}//cont aft -1/-2 exit?
	}
	return -2;
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
** //check DUPS + 0.2
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
		return (0);//thereis no room; or fault
		//if (ft_strchr))
	else
	{
	/*	if (lrc->br)
			if (!duplicheck(roomcor, lrc))
				return -2;
	*/	if (!(lrc->br = valroom_fill1((&lrc->br), roomcor)))
			return (0);
		lrc->rmi++;
	}
	return 10;
}

int					roomlinkblock(char **line, t_llrc *lrc, int fd)//mv ind!
{
	int		ret;
	int 	i;
	int		rm;
	int		v;

	i = 0;
	while (line[i])
	{
		ret = comstend(line[i]);
	//	if ((ret = comstend(*line))==0||ret==-3||ret==-1||ret==-2)
	//		free(*line);//repetiton of st/e/else?//KEKEEEEK
		if (ret == -1 ||ret == -2)/*)//save1/rol/cycle.iscom*/
		{
			if ((v = stcheck(line + i + 1, lrc, ret, fd)) < 0)//ret-check
				return (0);//fre?
			i += v;
		}
		if (ret == 1)
		{
			if ((rm = rmorlink(line[i], lrc)/*, (lrc->br))*/) == 2)
				return i;//(line[i]);//if no rms->lnks(li);//
		//	free(*line);
			if (rm == 0 || rm == -2)
				return (0);
		//	ok = (char**)lrc->br->content;
			//	printf("%s\n|%s\n|%s\n", ((char**)lrc->br->content)[0], ((char**)(lrc->br->content))[1], ((char**)(lrc->br->content))[2]);
		}
		++i;
	}
	return (0);//(*line);ERRvalrmonly
}
