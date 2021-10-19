/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:47:38 by sdalton           #+#    #+#             */
/*   Updated: 2021/04/27 12:47:38 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** char *strchr(const char *str, int c) searches for the first 
 * occurrence of the character c (an unsigned char) in the string 
 * pointed to by the argument str.
 * This returns a pointer to the first occurrence of the character
 * c in the string str, or NULL if the character is not found.**/

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	cu;

	i = 0;
	cu = c;
	while (str[i])
	{
		if (cu == (unsigned char)(str[i]))
			return ((char *)str + i);
		i++;
	}	
	if (!c)
		return ((char *)str + i);
	return (NULL);
}
