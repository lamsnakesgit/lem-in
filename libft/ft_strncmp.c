/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:29:38 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/22 20:38:40 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			k;
	int				r;
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	k = 1;
	r = 0;
	if (0 == n)
		return (0);
	while (uc1[i] == uc2[i] && uc1[i] && uc2[i] && k < n)
	{
		i++;
		k++;
	}
	r = uc1[i] - uc2[i];
	return (r);
}
