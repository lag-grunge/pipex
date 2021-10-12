#include "pipex.h"

void ft_redirect(int fd_in, int fd_out, int *pdes, int in_out)
{
	if (in_out == STDIN_FILENO)
	{
		dup2(pdes[0], STDIN_FILENO);
		close(pdes[0]);
		close(pdes[1]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	else if (in_out == STDOUT_FILENO)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		dup2(pdes[1], STDOUT_FILENO);
		close(pdes[0]);
		close(pdes[1]);
	}
}

void ft_exec(char *cmd, char *env[])
{
	char **s;
	char *exec_path;

	s = ft_split(cmd, ' ');
	ft_which(&exec_path, cmd, env);
	printf("%s\n", exec_path);
	clean_split(s, ft_spllen(s));
	execve(exec_path, s, env);
}

void ft_openfiles(int *fd_in, int *fd_out, char *argv[])
{

	*fd_in = open(argv[1], O_RDONLY);
	if (*fd_in == -1)
	{
		perror(argv[1]);
		exit(file1_not_open);
	}
	*fd_out = open(argv[4], O_WRONLY | O_CREAT, 0777);
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
	int 	status;

	pipe(pdes);
	pid = fork();
	if (pid == 0)
	{
		ft_redirect(fd_in, fd_out, pdes, STDIN_FILENO);
		ft_exec(argv[3], env);
		perror(argv[3]);
		exit(second_cmd_fail);
	}
	pid = fork();
	if (pid == 0)
	{
		ft_redirect(fd_in, fd_out, pdes, STDOUT_FILENO);
		ft_exec(argv[2], env);
		perror(argv[2]);
		exit(first_cmd_fail);
	}
	close(pdes[0]);
	close(pdes[1]);
	close(fd_in);
	close(fd_out);
	pid = wait(&status);
	if (WIFEXITED(status))
		printf("%d exit %d\n", pid, WEXITSTATUS(status));
	wait(&status);
	if (WIFEXITED(status))
		printf("%d exit %d\n", pid, WEXITSTATUS(status));
}

int main(int argc, char *argv[], char *env[])
{
	int fd_in;
	int fd_out;

	fd_in = 0;
	fd_out = 0;
	if (argc >= 5)
	{
		ft_openfiles(&fd_in, &fd_out, argv);
		ft_pipex(fd_in, fd_out, argv, env);
	}
	return (0);
}