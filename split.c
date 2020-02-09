/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:29:46 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/07 20:44:03 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int 		issplitsp(char *s, char c)
{
	int		i;
	int 	cnt;

	if (s[0] == c)
		return (0);
	i = 0;
	if (s[ft_strlen(s) - 1] == c)
		return (0);
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] == c)
				return (0);
			if (++cnt > 2)
				return (0);
		}
		++i;
	}
	return (1);
}
