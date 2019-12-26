/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:08:40 by ddratini          #+#    #+#             */
/*   Updated: 2019/12/17 16:31:15 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		write(1, s, ft_strlen(s));
	/*	while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	*/}
}
