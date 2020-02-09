/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:37:18 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/07 18:37:37 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

char		*ft_nstrsub(char const *s, unsigned int start, size_t len)
{
	char	*newsub;
	size_t	i;

	i = 0;
	if (s != 0)
	{
		newsub = (char *)malloc(sizeof(char) * (len + 1 + 1));
		if (!newsub)
			return (0);
		while (i < len)
		{
			newsub[i++] = s[start++];

		}
		newsub[i++] = s[start++];
		newsub[i] = '\0';
		return (newsub);
	}
	return (0);
}

