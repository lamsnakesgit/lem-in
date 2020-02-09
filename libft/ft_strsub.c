/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:59:59 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/19 17:50:33 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
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
     //   newsub[i++] = s[start++];
		newsub[i] = '\0';
		return (newsub);
	}
	return (0);
}
