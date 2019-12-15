/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:55:30 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/24 15:41:58 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_word_am(char const *s, char c)
{
	int amount;
	int i;

	i = 0;
	amount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			return (amount);
		while (s[i] && s[i] != c)
			i++;
		amount++;
		if (s[i] == '\0')
			return (amount);
	}
	return (amount);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		ffound;
	int		n;

	n = 0;
	i = 0;
	if (s == 0)
		return (0);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_word_am(s, c)) + 1)))
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		ffound = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > ffound)
			split[n++] = ft_strndup(s + ffound, i - ffound);
		if (!(ft_strndup(s + ffound, i - ffound)))
			return ((char **)ft_cleanmem(split));
	}
	split[n] = 0;
	return (split);
}
