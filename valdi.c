/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valdi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:31:43 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/09 14:31:48 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					checkcor(t_rooms *rm, t_llrc *llrc)
{
	t_list	*tmp;
	t_rooms	*n;

	tmp = llrc->br;
	while (tmp)
	{
		if (!(ft_strcmp(((t_rooms *)(tmp->content))->name_r, rm->name_r)))
		{
			freermlst(llrc, rm);
			return (0);
		}
		n = (t_rooms *)tmp->content;
		if (rm->x == (n)->x && rm->y == (n)->y)
		{
			freermlst(llrc, rm);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

long				valsp(char *av, long *sg)
{
	if (*av == '-')
		*sg = -1;
	if ((*av == ' ' && (*(av + 1) == ' ' || !*(av + 1))) \
	|| ((*av == '-' || *av == '+') && !ft_isdigit(*(av + 1))) \
	|| (*av != ' ' && *av != '-' && *av != '+' && !ft_isdigit(*av)) \
	|| (ft_isdigit(*av) && !ft_isdigit(*(av + 1)) && *(av + 1) != ' ' \
	&& *(av + 1)))
		return (0);
	return (1);
}

int					check_dig(char *av, int fn)
{
	int		i;
	char	*maxi;
	char	*mini;
	int		cmpr;

	i = -1;
	maxi = "2147483647";
	mini = "-2147483648";
	if (!fn && (cmpr = ft_strcmp(av, maxi)) > 0)
		return (0);
	else if (fn && ft_strcmp(av, mini) > 0)
		return (0);
	else
		return (1);
}

int					validate(int ac, char **av, int i, long fn)
{
	int		j;
	size_t	len;

	while (av[++i] && i < ac - 1)
	{
		fn = 0;
		j = -1;
		if (av[i][0] == '-')
			fn = 1;
		if ((len = ft_strlen(av[i])) > 11 || (len > 10 && !fn))
			return (0);
		while (av[i][++j])
		{
			if (fn && !j)
				++j;
			if (!ft_isdigit(av[i][j]))
				return (0);
			if (!valsp(av[i] + j, &fn))
				return (0);
			if ((j >= 10) || (j >= 9 && !fn))
				if (!check_dig(av[i], fn))
					return (0);
		}
	}
	return (1);
}
