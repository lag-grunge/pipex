/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:00:58 by sdalton           #+#    #+#             */
/*   Updated: 2021/04/26 14:07:53 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The strlen() function calculates the length of the string pointed 		*/	
/*		to by s, excluding the terminating null byte ('\0').				*/
/*	RETURN VALUE        													*/
/*		The strlen() function returns the number of bytes in the string		*/
/*		pointed to by s. 													*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
