/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:52:22 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/17 16:33:43 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				r;

	r = 0;
	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	r = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (r);
}
