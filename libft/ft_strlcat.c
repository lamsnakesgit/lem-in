/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:11:23 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/23 20:08:48 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			g;
	unsigned char	*sp;
	unsigned char	*dp;
	size_t			f;

	sp = (unsigned char *)src;
	dp = (unsigned char *)dst;
	i = 0;
	g = 0;
	f = ft_strlen((char *)dp);
	while (dp[i])
		i++;
	if (i < size)
	{
		while (sp[g] && i < size - 1)
			dp[i++] = sp[g++];
		dp[i] = '\0';
		return (f + ft_strlen((char *)src));
	}
	else
		return (ft_strlen((const char *)sp) + size);
}
