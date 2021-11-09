/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:34:30 by sdalton           #+#    #+#             */
/*   Updated: 2021/11/09 12:34:44 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 *  strlcpy() and strlcat() take the full 
 * size of the buffer (not just the length) and guarantee to NUL-terminate 
 * the result (as long as size is larger than 0 or, in the case of strlcat(), 
 * as long as there is at least one byte free in dst). Note that a byte 
 * for the NUL should be included in size. Also note that strlcpy()
 *  and strlcat() only operate on true ''C'' strings. This means that 
 * for strlcpy() src must be NUL-terminated and for strlcat() both src 
 * and dst must be NUL-terminated. **/

t_uint	ft_strlcpy(char *dst, const char *src, t_uint n)
{
	t_uint	cpy;
	t_uint	src_len;

	src_len = ft_strlen(src);
	if (n > src_len)
	{
		cpy = src_len;
		dst[cpy] = 0;
	}
	else if ((int)n > 0)
	{
		cpy = n - 1;
		dst[cpy] = 0;
	}
	else
		cpy = 0;
	ft_memcpy(dst, src, cpy);
	return (src_len);
}
