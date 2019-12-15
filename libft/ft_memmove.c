/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:58:57 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/24 15:00:37 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	while (src < dst && len-- > 0)
	{
		dp[len] = sp[len];
	}
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			dp[i] = sp[i];
			i++;
		}
	}
	return ((void *)dst);
}
