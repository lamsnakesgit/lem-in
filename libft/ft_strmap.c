/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:51:01 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/18 21:53:02 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*news;
	size_t	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		news = (char *)malloc(sizeof(char) * ((char)ft_strlen(s) + 1));
		if (news == NULL)
			return (0);
		while (s[i])
		{
			news[i] = (*f)(s[i]);
			i++;
		}
		news[i] = '\0';
		return ((char *)news);
	}
	return (NULL);
}
