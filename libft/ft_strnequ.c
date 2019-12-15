/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:03:08 by ddratini          #+#    #+#             */
/*   Updated: 2019/05/15 22:07:56 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int				res;
	size_t			i;

	i = 0;
	res = 0;
	if (n == 0)
		return (1);
	if (s1 == 0 || s2 == 0)
		return (0);
	if (ft_strncmp(s1, s2, n) != 0)
		return (0);
	else
		return (1);
}
