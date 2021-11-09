/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:43:10 by sdalton           #+#    #+#             */
/*   Updated: 2021/11/09 12:43:13 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef unsigned int	t_uint;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

size_t	ft_strlen(const char *s);
t_uint	ft_strlcpy(char *dst, const char *src, t_uint n);
t_uint	ft_strlcat(char *dst, const char *src, t_uint n);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t len);

char	*ft_substr(char const *s, t_uint start, size_t len);
char	**ft_split(const char *s, char c);
char	*get_next_word(char **tail, char c);
char	*get_next_word_beg(char *cur_delim, char c);
t_uint	get_number_words(const char *s, char c);
size_t	ft_spllen(char **spl);
void	clean_split(char **split, t_uint i);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

int		get_next_line(int fd, char **line);

#endif
