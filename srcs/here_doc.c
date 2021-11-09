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
	fd_in = open_for_write(HEREDOC, 0);
	line = NULL;
	while (ret == 1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (line)
		{
			ret = ft_strncmp(line, limiter, len_limiter + 1) != 0;
			if (ret)
				ft_putendl_fd(line, fd_in);
			free(line);
			line = 0;
		}
	}
	close(fd_in);
}
