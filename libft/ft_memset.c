/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:53:09 by sdalton           #+#    #+#             */
/*   Updated: 2021/05/04 08:35:44 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	DESCRIPTION        														*/
/*       The memset() function fills the first n bytes of the memory area	*/
/*      pointed to by s with the constant byte c.							*/
/*	RETURN VALUE         													*/
/*       The memset() function returns a pointer to the memory area s.		*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	cu;
	size_t			i;

	cu = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = cu;
		i++;
	}
	return (b);
}
