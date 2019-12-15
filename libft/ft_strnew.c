/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 23:00:29 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/24 15:16:40 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*newzstr;
	size_t	i;

	i = 0;
	if (size + 1 == 0)
		return (0);
	newzstr = (char *)malloc(sizeof(char) * (size + 1));
	if (newzstr == NULL)
		return (0);
	while (i <= size)
	{
		newzstr[i] = 0;
		i++;
	}
	return (newzstr);
}
