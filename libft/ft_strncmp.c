/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:48:22 by sdalton           #+#    #+#             */
/*   Updated: 2021/04/27 13:35:07 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** strncmp()	functions lexicographically compare the	null-
	 terminated	strings	s1 and s2.

	 The strncmp() function compares not more than len characters.  Because
	 strncmp() is designed for comparing strings rather	than binary data,
	 characters	that appear after a `\0' character are not compared.

RETURN VALUES
	 The strcmp() and strncmp()	functions return an integer greater than,
	 equal to, or less than 0, according as the	string s1 is greater than,
	 equal to, or less than the	string s2.  The	comparison is done using un-
	 signed characters,	so that	`\200' is greater than `\0'.
**/

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < len && c1[i] && c2[i])
	{
		if (c1[i] - c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	if (i == len)
		return (0);
	else
		return (c1[i] - c2[i]);
}
