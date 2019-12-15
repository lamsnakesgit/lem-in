/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:54:47 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/18 22:13:00 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				res;

	res = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (*c1 == *c2 && *c1)
	{
		c1++;
		c2++;
	}
	if ((res = *c1 - *c2) != 0)
		return (0);
	else
		return (1);
}
