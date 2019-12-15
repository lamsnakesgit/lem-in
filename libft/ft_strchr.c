/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:34:31 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/15 20:57:28 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strchr(const char *s, int c)
{
	char	rcharc;
	size_t	i;
	char	*chrs;

	chrs = (char *)s;
	i = 0;
	rcharc = (char)c;
	while (chrs[i] != rcharc && chrs[i])
	{
		i++;
	}
	if (chrs[i] == rcharc)
		return ((char *)s + i);
	else
		return (NULL);
}
