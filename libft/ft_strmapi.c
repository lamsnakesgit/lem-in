/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:42:29 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/18 22:02:33 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*news;
	size_t	i;

	i = 0;
	if (s != 0 && f != 0)
	{
		news = (char *)malloc(sizeof(char) * ((char)ft_strlen(s) + 1));
		if (news == 0)
			return (0);
		while (s[i])
		{
			news[i] = (*f)(i, s[i]);
			i++;
		}
		news[i] = '\0';
		return (news);
	}
	return (0);
}
