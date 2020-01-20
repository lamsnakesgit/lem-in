/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:37:44 by ddratini          #+#    #+#             */
/*   Updated: 2019/05/17 17:37:48 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_cleanmem(char **split)
{
	int i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		++i;
	}
/*	while (*split++)
		free(*split);
*/
	free(split[i]);
	free(split);
	split = 0;
	return (0);
}
