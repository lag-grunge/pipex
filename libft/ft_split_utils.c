/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:38:35 by sdalton           #+#    #+#             */
/*   Updated: 2021/11/09 12:38:38 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_word_beg(char *cur_delim, char c)
{
	t_uint	i;

	i = 0;
	while (cur_delim[i] && cur_delim[i] == c)
		i++;
	return (cur_delim + i);
}

t_uint	get_number_words(const char *s, char c)
{
	char	*cur_delim;
	char	*tail;
	t_uint	words;

	tail = get_next_word_beg((char *)s, c);
	cur_delim = tail;
	words = 0;
	while (*tail && cur_delim)
	{
		cur_delim = ft_strchr(tail, c);
		if (cur_delim)
			tail = get_next_word_beg(cur_delim, c);
		words++;
	}
	return (words);
}

size_t	ft_spllen(char **spl)
{
	size_t	i;

	i = 0;
	while (*spl++)
		i++;
	return (i);
}

void	clean_split(char **split, t_uint i)
{
	while (i > 0)
	{
		free(split[i - 1]);
		i--;
	}
}
