#include "pipex.h"

int	read_here_doc(char *limiter)
{
    char    *line;
    size_t  len_limiter;
    int     ret;
    int     fd_in;

    ret = 1;
    len_limiter = ft_strlen(limiter);
	fd_in = open_for_write("heredoc");
	line = NULL;
    while (ret)
    {
		if (line)
		{
			ft_putstr_fd(line, fd_in);
			free(line);
		}
		ret = get_next_line(STDIN_FILENO, &line);
		if (line && !ft_strncmp(line, limiter, len_limiter + 1))
			break;
    }
	return (fd_in);
}
