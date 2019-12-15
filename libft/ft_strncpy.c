/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:18:09 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/16 20:21:07 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	i = 0;
	while (i < len && sp[i])
	{
		dp[i] = sp[i];
		i++;
	}
	while (i < len)
	{
		dp[i] = '\0';
		i++;
	}
	return (dst);
}
