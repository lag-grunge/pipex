/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:13:44 by sdalton           #+#    #+#             */
/*   Updated: 2021/04/26 13:18:53 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** The memchr() function scans the initial n bytes of the memory
       area pointed to by s for the first instance of c.  Both c and the
       bytes of the memory area pointed to by s are interpreted as
       unsigned char.
        The memchr() functions return a pointer to the
       matching byte or NULL if the character does not occur in the
       given memory area.
**/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cu;
	unsigned char	*sc;

	i = 0;
	cu = c;
	sc = (unsigned char *)s;
	while (i < n)
	{
		if (sc[i] == cu)
			return (sc + i);
		i++;
	}
	return (NULL);
}
