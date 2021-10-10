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

enum e_errors	{
	nopath_in_env = 1,
	not_perms_for_exec = 2,
	not_fnd_bin_in_path = 3
};


void ft_which(char **exec_path, char *cmd, char *env[]);

#endif