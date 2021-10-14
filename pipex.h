#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"
# define BAD_ENV_MSG "No PATH var found in environment"
# define PERM_DENIAL_MSG "Permission denied"
# define BIN_NOT_FOUND_MSG "No such file"
# define HEREDOC "here_doc"

enum e_errors	{
	nopath_in_env = 1,
	not_perms_for_exec = 2,
	not_fnd_bin_in_path = 3,
	file1_not_open = 4,
	file2_not_open = 5,
	first_cmd_fail = 6,
	second_cmd_fail = 7,
	cmd_exec_fail = 8,
	pipe_fail = 9,
	fork_fail = 10
};

enum e_proc_redirect	{
	parent = -1,
	last = -2,
	first = -3
};

void ft_which(char **exec_path, char *cmd, char *env[]);
void ft_redirect_bonus(int fd_in_out[2], int *pdes, int in_out);

#endif