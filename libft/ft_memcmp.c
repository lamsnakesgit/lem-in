/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:28:41 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/13 20:26:53 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	size_t			i;
	int				ucdiff;

	ucdiff = 0;
	i = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (i < n)
	{
		if (u1[i] != u2[i])
		{
			ucdiff = u1[i] - u2[i];
			return (ucdiff);
		}
		i++;
	}
	return (0);
}
