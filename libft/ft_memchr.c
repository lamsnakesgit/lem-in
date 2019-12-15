/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:29:03 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/19 14:01:53 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucpts;
	unsigned char	charc;
	size_t			i;

	charc = (unsigned char)c;
	ucpts = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ucpts[i] == charc)
			return (ucpts + i);
		i++;
	}
	return (NULL);
}
