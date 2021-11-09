/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:05:05 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/21 08:05:25 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_for_read(char *filename)
{
	int	fd_in;

	fd_in = open(filename, O_RDONLY);
	if (fd_in == -1)
	{
		perror(filename);
		exit(file1_not_open);
	}
	return (fd_in);
}

int	open_for_write(char *filename, int append)
{
	int	fd_out;

	fd_out = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd_out == -1)
	{
		if (errno != EEXIST)
		{
			perror(filename);
			exit(file2_not_open);
		}
		if (append)
			fd_out = open(filename, O_WRONLY | O_APPEND);
		else
			fd_out = open(filename, O_WRONLY | O_TRUNC);
		if (fd_out == -1)
			exit(file2_not_open);
	}
	return (fd_out);
}

void	ft_redirect(int *pdes, int in_out)
{
	if (in_out == STDIN_FILENO)
		dup2(pdes[0], STDIN_FILENO);
	else if (in_out == STDOUT_FILENO)
		dup2(pdes[1], STDOUT_FILENO);
	else if (in_out == -1)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
	}
	close(pdes[0]);
	close(pdes[1]);
}

void	ft_exec(char *cmd, char *env[])
{
	char	**s;
	char	*exec_path;

	s = ft_split(cmd, ' ');
	ft_which(&exec_path, s[0], env);
	execve(exec_path, s, env);
}

void	free_2d_array(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
