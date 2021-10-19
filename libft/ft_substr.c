/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:03:36 by sdalton           #+#    #+#             */
/*   Updated: 2021/05/11 14:25:53 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Function name ft_substr											*/
/*Prototype char *ft_substr(char const *s, unsigned int start,		*/
/*size_t len);														*/
/*Turn in files -													*/
/*Parameters #1. The string from which to create the substring.		*/
/*#2. The start index of the substring in the string				*/
/*’s’.																*/
/*#3. The maximum length of the substring.							*/
/*Return value The substring. NULL if the allocation fails.			*/
/*External functs. malloc											*/
/*Description Allocates (with malloc(3)) and returns a substring	*/
/*from the string ’s’.												*/
/*The substring begins at index ’start’ and is of					*/
/*maximum size ’len’.												*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	ss_len;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	ss_len = len;
	if ((int)len < 0 || start > s_len)
		return (ft_strdup(""));
	else if (start <= s_len && len + start > s_len)
		ss_len = s_len - start;
	ss = malloc(sizeof(char) * (ss_len + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (i < ss_len)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[ss_len] = 0;
	return (ss);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		printf("%s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
	}
	return (0);
}*/
