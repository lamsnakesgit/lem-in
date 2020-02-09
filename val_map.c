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

/*
** -1 = start, -2 = end 0 = comment, 1 = line
** -3 = unknown command
*/

int					comstend(char *line)
{
	ft_putendl(line);
	if (line && line[0] == '#' && line + 1 && line[1] == '#')
	{
		if (!ft_strcmp(line + 2, "start"))
			return (-1);
		if (!ft_strcmp(line + 2, "end"))
			return (-2);
		else
			return (-3);
	}
	else if (line[0] == '#')
		return (0);
	return (1);
}

int					stcheck(char **line, t_llrc *lrc, int cm)
{
	int re;
	int rvl;
	int i;

	i = -1;
	cm == -2 ? ++lrc->end : ++lrc->st;
	if (lrc->st > 1 || lrc->end > 1)
		return (-2);
	while (line[++i])
	{
		if ((re = comstend(line[i])) != 1)
		{//	free(*line);
			if (re == -2 || re == -1)
				return (-2);
		}
		else if (re == 1)
		{//freelst?
			if ((rvl = rmorlink(line[i], lrc)) == 2 || !rvl)
				return (-2);
			if (savemarg(lrc, cm) == 0)
				return (-2);//nonfree?/ret?
			return (1 + i);
		}
	}
	return (-2);
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

int					rmorlink(char *line, t_llrc *lrc)//, t_list *rl)
{
	char	**roomcor;

	if (!ft_strchr(line, ' '))//btwr-name-1//lol/KO
	{
		return (2);
	}
	if (!(roomcor = valrmc_s(line, lrc)))
		return (0);
	else
	{
		if (!(lrc->br = valroom_fill1((&lrc->br), roomcor, lrc)))
			return (0);
		lrc->rmi++;
	}
	return (10);
}

int					roomlinkblock(char **line, t_llrc *lrc)//mv ind!
{
	int		ret;
	int		i;
	int		rm;
	int		v;

	i = 0;
	while (line[i])
	{
		ret = comstend(line[i]);
		if (ret == -1 || ret == -2)
		{
			if ((v = stcheck(line + i + 1, lrc, ret)) < 0)
				return (0);//fre?
			i += v;
		}
		if (ret == 1)
		{
			if ((rm = rmorlink(line[i], lrc)) == 2)
				return (i);
			if (rm == 0 || rm == -2)
				return (0);
		}
		++i;
	}
	return (0);
}
