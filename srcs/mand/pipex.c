/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:27:12 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/21 08:27:14 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pipex(char *argv[], char *env[])
{
	int		pdes[2];
	pid_t	pid;
	pid_t	pid2;

	pipe(pdes);
	pid = fork();
	if (pid == 0)
	{
		ft_redirect(pdes, STDIN_FILENO);
		ft_exec(argv[3], env);
		exit(second_cmd_fail);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		ft_redirect(pdes, STDOUT_FILENO);
		ft_exec(argv[2], env);
		exit(first_cmd_fail);
	}
	ft_redirect(pdes, -1);
	wait(NULL);
	wait(NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	int	fd_in;
	int	fd_out;

	if (argc != 5)
	{
		write(STDERR_FILENO, ARG_ERROR_MSG, ft_strlen(ARG_ERROR_MSG));
		exit(argv_error);
	}
	fd_in = open_for_read(argv[1]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	fd_out = open_for_write(argv[4], 0);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	ft_pipex(argv, env);
	return (0);
}
