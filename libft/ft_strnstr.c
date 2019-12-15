/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:01:04 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/22 20:11:15 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*hayst;
	unsigned char	*nee;
	size_t			i;
	size_t			j;
	size_t			lenee;

	j = 0;
	hayst = (unsigned char *)haystack;
	nee = (unsigned char *)needle;
	if (*nee == '\0')
		return ((char *)haystack);
	while (hayst[j] && j < len)
	{
		i = 0;
		while (nee[i] == hayst[j + i] && j + i < len)
		{
			if (nee[i + 1] == '\0')
				return ((char *)haystack + j);
			i++;
		}
		j++;
		if ((lenee = ft_strlen((const char *)nee)) > len)
			return (NULL);
	}
	return (NULL);
}
