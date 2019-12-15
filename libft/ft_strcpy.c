/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:54:52 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/13 21:17:50 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	unsigned char	*dp;
	unsigned char	*sp;
	int				i;

	i = 0;
	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	while (sp[i])
	{
		dp[i] = sp[i];
		i++;
	}
	dp[i] = sp[i];
	return (dst);
}
