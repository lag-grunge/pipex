/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:28:40 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/21 08:28:54 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	start_cmds(char *cmd, int *pdes, char *env[])
{
	pid_t	pid;

	if (pipe(pdes) == -1)
		exit(pipe_fail);
	pid = fork();
	if (pid < 0)
		exit(fork_fail);
	else if (pid == 0)
	{
		ft_redirect(pdes, STDOUT_FILENO);
		ft_exec(cmd, env);
	}
	ft_redirect(pdes, STDIN_FILENO);
}

static void	start_h_doc(char *cmd, char *lim, int *pdes, char *env[])
{
	int pid;
	int h_doc[2];

	if (pipe(h_doc) == -1)
		exit(pipe_fail);
	if (pipe(pdes) == -1)
		exit(pipe_fail);
	pid = fork();
	if (pid < 0)
		exit(fork_fail);
	else if (pid == 0)
	{
		ft_redirect(h_doc, STDIN_FILENO);
		ft_redirect(pdes, STDOUT_FILENO);
		ft_exec(cmd, env);
	}
	ft_redirect(h_doc, STDOUT_FILENO);
	read_here_doc(lim);
	ft_redirect(pdes, STDIN_FILENO);
}

static void	start_last(char *cmd, char *env[])
{
	int pid;

	pid = fork();
	if (pid < 0)
		exit(fork_fail);
	else if (pid == 0)
		ft_exec(cmd, env);
}


static void	ft_pipex(int cmd_start, int cmds_num, char *argv[], char *env[])
{
	int		pdes[2];
	int		i;

	i = H_DOC;
	if (H_DOC)
		start_h_doc(argv[cmd_start], argv[2], pdes, env);
	ft_openfiles(argv[1], argv[cmds_num + cmd_start], H_DOC);
	while (i < cmds_num - 1)
	{
		start_cmds(argv[cmd_start + i], pdes, env);
		i++;
	}
	start_last(argv[cmd_start + cmds_num - 1], env);
	ft_redirect(pdes, -1);
	while (cmds_num > 0)
	{
		wait(NULL);
		cmds_num--;
	}
}

int	main(int argc, char *argv[], char *env[])
{
	if (argc < 5)
	{
		write(STDERR_FILENO, ARG_ERROR_MSG, ft_strlen(ARG_ERROR_MSG));
		return (argv_error);
	}
	if (H_DOC && argc == 5)
	{
		write(STDERR_FILENO, ARG_ERROR_MSG, ft_strlen(ARG_ERROR_MSG));
		return (argv_error);
	}
	if (H_DOC)
		ft_pipex(3, argc - 4, argv, env);
	else
		ft_pipex(2, argc - 3, argv, env);
	return (0);
}
