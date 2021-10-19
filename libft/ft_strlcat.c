/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:19:37 by sdalton           #+#    #+#             */
/*   Updated: 2021/05/06 16:46:02 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 *  strlcpy() and strlcat() take the full 
 * size of the buffer (not just the length) and guarantee to NUL-terminate 
 * the result (as long as size is larger than 0 or, in the case of strlcat(), 
 * as long as there is at least one byte free in dst). Note that a byte 
 * for the NUL should be included in size. Also note that strlcpy()
 *  and strlcat() only operate on true ''C'' strings. This means that 
 * for strlcpy() src must be NUL-terminated and for strlcat() both src 
 * and dst must be NUL-terminated. **/

t_uint	ft_strlcat(char *dst, const char *src, t_uint size)
{
	char		*cp;
	t_uint		dst_len;
	t_uint		src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	cp = dst + dst_len;
	if (size >= dst_len + src_len + 1)
	{
		ft_memcpy(cp, src, src_len);
		dst[dst_len + src_len] = 0;
		return (dst_len + src_len);
	}
	else if (size >= dst_len + 1)
	{
		ft_memcpy(cp, src, size - dst_len - 1);
		dst[size - 1] = 0;
		return (dst_len + src_len);
	}
	else
		return (size + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
     char s1[4] = "";
     char s2[4] = "";
  	t_uint r1 = __builtin___strlcat_chk (s1, "thx to ntoniolo for this test !", 
	4, __builtin_object_size (s1, 2 > 1 ? 1 : 0));
  	t_uint r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	printf("%s\n", s1);
	printf("%s\n", s2);
}
*/
