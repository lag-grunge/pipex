/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:33:40 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/21 08:33:41 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# ifdef BONUS
#  define ARG_ERROR_MSG "Few arguments. Usage: \n \
bonus 			./pipex file1 cmd1 cmd2 ... cmdn file2\n \
here_doc 		./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.\n"
# else
#  define ARG_ERROR_MSG "Too much arguments. Usage: 5 arguments\n \
./pipex	file1 cmd1 cmd2 file2\n"
# endif
# define BAD_ENV_MSG "No PATH var found in environment"
# define PERM_DENIAL_MSG "Permission denied"
# define BIN_NOT_FOUND_MSG "No such file"
# define HEREDOC "here_doc"

enum e_errors	{
	argv_error = 1,
	nopath_in_env = 2,
	not_perms_for_exec = 3,
	not_fnd_bin_in_path = 4,
	file1_not_open = 5,
	file2_not_open = 6,
	first_cmd_fail = 7,
	second_cmd_fail = 8,
	cmd_exec_fail = 9,
	pipe_fail = 10,
	fork_fail = 11,
	malloc_error = 12
};

void	ft_which(char **exec_path, char *cmd, char *env[]);
int		open_for_write(char *filename, int append);
int		open_for_read(char *filename);
void	read_here_doc(char *limiter);
void	ft_redirect(int *pdes, int in_out);
void	ft_exec(char *cmd, char *env[]);
void	free_2d_array(int **arr, int size);

#endif
