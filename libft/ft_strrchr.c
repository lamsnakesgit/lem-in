/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:57:46 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/23 21:44:47 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	rcrc;
	char	*chars;

	chars = (char *)s;
	rcrc = (char)c;
	i = 0;
	while (chars[i])
		i++;
	if (chars[i] == rcrc)
		return ((char *)s + i);
	i -= 1;
	while (chars[i] != chars[0] && chars[i] != rcrc)
		i--;
	if (chars[i] == rcrc)
		return ((char *)s + i);
	else
		return (NULL);
}
