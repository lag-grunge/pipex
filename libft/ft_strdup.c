/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 08:29:25 by sdalton           #+#    #+#             */
/*   Updated: 2021/04/28 11:19:48 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*DESCRIPTION         top*/
/*The strdup() function returns a pointer to a new string which is*/
/*a duplicate of the string s.  Memory for the new string is*/
/*obtained with malloc(3), and can be freed with free(3).*/
/**/
/*The strndup() function is similar, but copies at most n bytes.*/
/*If s is longer than n, only n bytes are copied, and a terminating*/
/*null byte ('\0') is added.*/
/**/
/*strdupa() and strndupa() are similar, but use alloca(3) to*/
/*allocate the buffer.  They are available only when using the GNU*/
/*GCC suite, and suffer from the same limitations described in*/
/*alloca(3).*/
/*RETURN VALUE         top*/
/*On success, the strdup() function returns a pointer to the*/
/*duplicated string.  It returns NULL if insufficient memory was*/
/*available, with errno set to indicate the error.*/

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ds;

	len = ft_strlen(s);
	ds = (char *)malloc(sizeof(char) * (len + 1));
	if (!ds)
		return (NULL);
	ft_strlcpy(ds, s, len + 1);
	return (ds);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char s[20];
	char *fake;
	char *s1;
	char *s2;

	fake = NULL;
	s2 = ft_strdup(fake);
	s1 = strdup(fake);
	printf("%s\n", s1);
	printf("%s\n", s2);
	
	return (0);
}
*/
