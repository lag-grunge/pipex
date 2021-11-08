/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:14:25 by sdalton           #+#    #+#             */
/*   Updated: 2021/05/11 13:33:26 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*	get_next_word(char **tail, char c)
{
	char		*word;
	char		*cur_delim;
	char		*tail_val;

	tail_val = get_next_word_beg(*tail, c);
	cur_delim = ft_strchr(tail_val, c);
	if (!cur_delim)
		cur_delim = ft_strchr(tail_val, 0);
	word = (char *)malloc(sizeof(char) * (cur_delim - tail_val + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, tail_val, cur_delim - tail_val + 1);
	*tail = cur_delim;
	return (word);
}

char	**ft_split(const char *s, char c)
{	
	unsigned 	words;
	char		**split;
	char		*tail;
	unsigned	i;

	i = 0;
	words = get_number_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	tail = (char *)s;
	if (!split)
		return (NULL);
	split[words] = NULL;
	while (i < words)
	{
		split[i] = get_next_word(&tail, c);
		if (!split[i])
		{
			clean_split(split, i);
			return (NULL);
		}
		i++;
	}
	return (split);
}
/*
#include <stdio.h>

static void	print_split(char **split)
{
    printf("%p\n", split);
	while (*split)
	{
		printf("%s\n", *split);
		split++;
	}
}

int main()
{
	print_split(ft_split(" fhgdfh fgdfh fdhdfh   ", 32));

	print_split(ft_split("fhgdfh fgdfh fdhdfh", 32));
	print_split(ft_split("fhgdfh fgdfh fdhdfh    ", 32));
	print_split(ft_split("    fhgdfh fgdfh fdhdfh", 32));
	print_split(ft_split("    ", 32));
	print_split(ft_split("", 32));

	return (0);
}*/