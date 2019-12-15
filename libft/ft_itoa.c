/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:40:29 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/22 20:38:56 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_dig_am(int nu)
{
	int a;

	a = 0;
	if (nu == 0)
		return (1);
	while (nu)
	{
		nu /= 10;
		a++;
	}
	return (a);
}

char				*ft_itoa(int n)
{
	char	*str;
	int		sgn;
	int		dig;

	dig = ft_dig_am(n);
	sgn = (n < 0) ? 1 : 0;
	if (!(str = ft_strnew((size_t)(dig + sgn))))
		return (0);
	if (sgn)
		str[0] = '-';
	else if (n >= 0)
		dig--;
	if (n == 0)
		return (ft_strdup("0"));
	str[dig] = '\0';
	while (n)
	{
		if (n > 0)
			str[dig--] = '0' + n % 10;
		else
			str[dig--] = -(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
