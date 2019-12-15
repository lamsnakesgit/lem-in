/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:55:17 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/24 15:30:14 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long int		i;
	unsigned long int		r;
	int						sign;

	sign = 1;
	r = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 14) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((r > 922337203685477580 || \
				(r == 922337203685477580 && (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		if ((r > 922337203685477580 || \
				(r == 922337203685477580 && (str[i] - '0') > 8)) && sign == -1)
			return (0);
		r = r * 10 + (unsigned long long int)(str[i] - '0');
		i++;
	}
	return ((unsigned long long int)r * sign);
}
