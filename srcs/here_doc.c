/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:15:06 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/21 08:25:55 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_here_doc(char *limiter)
{
	char	*line;
	size_t	len_limiter;
	int		ret;
	int		fd_in;

	ret = 1;
	len_limiter = ft_strlen(limiter);
	fd_in = open_for_write("heredoc");
	line = NULL;
	while (ret)
	{
		if (line)
		{
			ft_putendl_fd(line, fd_in);
			free(line);
		}
		ret = get_next_line(STDIN_FILENO, &line);
		if (line && !ft_strncmp(line, limiter, len_limiter + 1))
			break ;
	}
	close(fd_in);
}
