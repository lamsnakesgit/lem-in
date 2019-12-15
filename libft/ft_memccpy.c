/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:27:29 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/19 14:01:12 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dsg;
	unsigned char	*str;
	unsigned char	charc;
	size_t			i;

	charc = (unsigned char)c;
	dsg = (unsigned char *)dst;
	str = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dsg[i] = str[i];
		if (str[i] == charc)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
