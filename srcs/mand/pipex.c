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

static void	ft_pipex(char *argv[], char *env[], int sav)
{
	int		pdes[2];
	pid_t	pid;
	pid_t	pid2;
	int		s[2];

	if (pipe(pdes) == -1)
		exit(pipe_fail);
	pid = fork();
	if (pid < 0)
		exit(fork_fail);
	else if (pid == 0)
	{
		ft_redirect(pdes, STDOUT_FILENO);
		ft_exec(argv[2], env);
	}
	pid2 = fork();
	if (pid2 < 0)
		exit(fork_fail);
	else if (pid2 == 0)
	{
		ft_redirect(pdes, STDIN_FILENO);
		ft_exec(argv[3], env);
	}
	ft_redirect(pdes, -1);
	wait(NULL);
	wait(NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	int 	sav;

	sav = dup(STDIN_FILENO);
	if (argc != 5)
	{
		write(STDERR_FILENO, ARG_ERROR_MSG, ft_strlen(ARG_ERROR_MSG));
		exit(argv_error);
	}
	ft_openfiles(argv[1], argv[4], 0);
	ft_pipex(argv, env, sav);
	dup2(sav, STDOUT_FILENO);
	close(sav);
	return (0);
}
