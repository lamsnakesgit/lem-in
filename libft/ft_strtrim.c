/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:01:29 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/22 20:53:39 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*cop;
	size_t			i;
	unsigned int	start;
	size_t			leng;

	i = 0;
	if (s == 0)
		return (0);
	while ((s[i]) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (!s[i])
		return (ft_strnew(0));
	start = i;
	i = ft_strlen(s) - 1;
	while ((s[i]) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	leng = i - start + 1;
	if (!(cop = ft_strnew(i - start + 1)))
		return (0);
	i = 0;
	while (i < leng)
		cop[i++] = s[start++];
	cop[i] = '\0';
	return (cop);
}
