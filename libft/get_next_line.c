#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static size_t	ft_realloc(char **buf, size_t buf_size)
{
	char *tmp;

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

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	*buf;
	size_t	i;
	size_t  cur_BUFFER_SIZE;

	cur_BUFFER_SIZE = BUFFER_SIZE;
	buf = malloc(cur_BUFFER_SIZE);
	if (!buf)
		return (-1);
	i = 0;
	*line = 0;
	ret = read(fd, buf + i, 1);
	if (ret != 1)
		return (ret);
	while (ret == 1 && buf[i] != '\n')
	{
		i++;
		ret = read(fd, buf + i, 1);
		if (i + 1 == cur_BUFFER_SIZE)
			cur_BUFFER_SIZE = ft_realloc(&buf, cur_BUFFER_SIZE);
		if (!cur_BUFFER_SIZE || ret == -1)
			return (-1);
	}
	buf[i] = 0;
	*line = buf;
	return (ret);
}
/*#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		char *line = 0;
		while (get_next_line(fd, &line))
		{
			ft_putstr_fd(line, 1);
			write(1, "\n", 1);
			free(line);
			line = 0;
		}
		if (line)
		{
			ft_putstr_fd(line, 1);
			write(1, "\n", 1);
			free(line);
			line = 0;
		}
	}
	return (0);
}*/
