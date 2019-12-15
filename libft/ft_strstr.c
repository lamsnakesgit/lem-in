/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:25:25 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/18 19:02:57 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*hayst;
	unsigned char	*nee;
	int				i;
	int				j;

	hayst = (unsigned char *)haystack;
	nee = (unsigned char *)needle;
	j = 0;
	if (*nee == '\0')
		return ((char *)haystack);
	i = 0;
	while (hayst[j])
	{
		i = 0;
		while (nee[i] == hayst[j + i])
		{
			if (nee[i + 1] == '\0')
				return ((char *)haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
