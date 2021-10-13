#include "pipex.h"

void ft_redirect(int fd_in, int fd_out, int *pdes, int in_out)
{
	if (in_out == STDIN_FILENO)
	{
		dup2(pdes[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
	}
	else if (in_out == STDOUT_FILENO)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(pdes[1], STDOUT_FILENO);
	}
	else if (in_out == -1)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
	}
	close(fd_in);
	close(fd_out);
	close(pdes[0]);
	close(pdes[1]);
}

void ft_exec(char *cmd, char *env[])
{
	char **s;
	char *exec_path;

	s = ft_split(cmd, ' ');
	ft_which(&exec_path, s[0], env);
	execve(exec_path, s, env);
	perror(s[0]);
}

void ft_openfiles(int *fd_in, int *fd_out, char *argv[])
{
	if (!ft_strncmp("here_doc", argv[1]))
	{

	}
	*fd_in = open(argv[1], O_RDONLY);
	if (*fd_in == -1)
	{
		perror(argv[1]);
		exit(file1_not_open);
	}
	*fd_out = open(argv[4], O_WRONLY | O_CREAT, 0666);
	if (*fd_out == -1)
	{
		if (errno != EEXIST)
		{
			perror(argv[4]);
			exit(file2_not_open);
		}
		*fd_out = open(argv[4], O_WRONLY);
	}
}

void ft_pipex(int fd_in, int fd_out, char *argv[], char *env[])
{
	int		pdes[2];
	pid_t	pid;
	pid_t	pid2;

	pipe(pdes);
	pid = fork();
	if (pid == 0)
	{
		ft_redirect(fd_in, fd_out, pdes, STDIN_FILENO);
		ft_exec(argv[3], env);
		exit(second_cmd_fail);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		ft_redirect(fd_in, fd_out, pdes, STDOUT_FILENO);
		ft_exec(argv[2], env);
		exit(first_cmd_fail);
	}
	ft_redirect(fd_in, fd_out, pdes, -1);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	char *str, *tmp;
	str = ft_itoa(getpid());
	tmp = ft_strjoin("leaks ", str);
	system(tmp);
	free(str);
	free(tmp);
	while (1)
		;
}

int main(int argc, char *argv[], char *env[])
{
	int fd_in;
	int fd_out;

	fd_in = 0;
	fd_out = 0;
	ft_openfiles(&fd_in, &fd_out, argv);
	ft_pipex(fd_in, fd_out, argv, env);
	return (0);
}