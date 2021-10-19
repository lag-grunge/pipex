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

#include <stdlib.h>


static char*	get_next_word_beg(char *cur_delim, char c) 
{
	unsigned	i;

	i = 0;	
	while (cur_delim[i] && cur_delim[i] == c)
		i++;
	return (cur_delim + i); 
}

static unsigned get_number_words(const char *s, char c)
{
	char		*cur_delim;
	char		*tail;
	unsigned	words;
	unsigned	s_len;
	size_t		ft_strlen(const char *);
	char*		ft_memchr(const char *, char, size_t);
	s_len = ft_strlen(s);
	tail = get_next_word_beg((char *)s, c);
	words = 0;
	while (*tail)
	{	
		cur_delim = ft_memchr(tail, c, s_len - (tail - (char *)s));
		if (!cur_delim && *tail)
		{
			words++;
			break;
		}
		tail = get_next_word_beg(cur_delim, c);
		words++;
	}
	return (words);
}

static char*	get_next_word(char **tail, char c)
{
	char		*word;
	char		*cur_delim;
	char		*ft_strchr(const char *, int);
	char		*ft_strlcpy(char *, const char *, size_t);
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

static void		clean_split(char **split, unsigned i)
{
	while (i > 0)
	{
		free(split[i - 1]);
		i--;
	}
}

char	**ft_split(const char *s, char c)
{	
	unsigned 	words;
	char		**split;
	char		**tail;
	char		*tail_val;
	unsigned	i;

	i = 0;
	words = get_number_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	tail_val = (char *)s;
	tail = &tail_val;
	if (!split) 
		return (NULL);
	split[words] = NULL;
	while (i < words)
	{
		split[i] = get_next_word(tail, c);
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
}
*/
