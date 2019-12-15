/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:59:59 by ddratini          #+#    #+#             */
/*   Updated: 2019/04/24 15:25:57 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptrm;

	if (size + 1 == 0)
		return (0);
	ptrm = (void *)malloc(size);
	if (ptrm == NULL)
		return (0);
	ft_bzero(ptrm, size);
	return ((void *)ptrm);
}
