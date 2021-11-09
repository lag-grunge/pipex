/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:18:59 by sdalton           #+#    #+#             */
/*   Updated: 2021/11/09 12:19:08 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

static size_t	ft_realloc(char **buf, size_t buf_size)
{
	char	*tmp;

	tmp = *buf;
	*buf = malloc(buf_size * 2);
	if (!*buf)
	{
		free(tmp);
		return (0);
	}
	ft_memcpy(*buf, tmp, buf_size);
	free(tmp);
	return (buf_size * 2);
}

static void	ft_free(char **buf)
{
	free(*buf);
	*buf = NULL;
}

static int	read_byte(int fd, char **buf_ptr, size_t i)
{
	static size_t	cur_buffer_size = BUFFER_SIZE;
	int				ret;

	ret = read(fd, *buf_ptr + i, 1);
	if (ret == 1 && (*buf_ptr)[i] == '\n')
	{
		cur_buffer_size = BUFFER_SIZE;
		return (1);
	}
	if (ret == 1 && i + 2 == cur_buffer_size)
		cur_buffer_size = ft_realloc(buf_ptr, cur_buffer_size);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	*buf;
	size_t	i;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (-1);
	i = 0;
	ret = read(fd, buf, 1);
	while (ret == 1 && buf[i] != '\n')
	{
		i++;
		ret = read_byte(fd, &buf, i);
	}
	if (ret == -1 || (ret == 0 && i == 0))
		ft_free(&buf);
	else
		buf[i] = 0;
	*line = buf;
	return (ret);
}
