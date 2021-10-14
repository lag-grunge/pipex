#include "pipex.h"

static void	ft_redirect_parent(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(fd_in_out[0]);
}

static void ft_redirect_common(void)
{
	close(fd_in_out[1]);
	close(pdes[0]);
	close(pdes[1]);
}

void	ft_redirect_bonus(int fd_in_out[2], int *pdes, int in_out)
{
	if (in_out == parent)
		ft_redirect_parent();
	else if (in_out == first)
	{
		if (fd_in_out[0] != STDIN_FILENO)
		{
			dup2(fd_in_out[0], STDIN_FILENO);
			close(fd_in_out[0]);
		}
		dup2(pdes[1], STDOUT_FILENO);
	}
	else if (in_out == last)
	{
		dup2(pdes[0], STDIN_FILENO);
		dup2(fd_in_out[1], STDOUT_FILENO);
	}
	else if (in_out == STDIN_FILENO)
	{
		dup2(pdes[0], STDIN_FILENO);
		close(fd_in_out[0]);
	}
	else if (in_out == STDOUT_FILENO)
		dup2(pdes[1], STDOUT_FILENO);
	ft_redirect_common();
}

