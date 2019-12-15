/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:48:40 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/19 16:00:49 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*concat2;
	size_t			i;
	unsigned char	*cu1;
	unsigned char	*cu2;
	size_t			j;

	j = 0;
	cu1 = (unsigned char *)s1;
	cu2 = (unsigned char *)s2;
	i = -1;
	if (s1 != 0 && s2 != 0)
	{
		concat2 = ft_strnew(ft_strlen(s2) + ft_strlen(s1) + 1);
		if (!concat2)
			return (0);
		while (cu1[++i])
			concat2[i] = cu1[i];
		while (cu2[j])
			concat2[i++] = cu2[j++];
		concat2[i] = '\0';
		return (concat2);
	}
	return (0);
}
