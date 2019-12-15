/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:45:05 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/24 15:24:03 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	const char		*sp;
	char			*dp;

	if (!dst && !src)
		return (NULL);
	i = 0;
	sp = (const char *)src;
	dp = (char *)dst;
	while (n--)
	{
		dp[i] = sp[i];
		i++;
	}
	return ((void *)dst);
}
