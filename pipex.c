#include "pipex.h"

void ft_pipex(int argc, char *argv[], char *env[])
{
	int pdes[2];
	int fd;
	char *cmd;

	printf("%d %s\n", argc, argv[argc - 1]);
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		char **s = ft_split(argv[2], ' ');
		ft_which(&cmd, s[0], env);
		execve(s[0], s, env);
		perror(s[0]);
	}
	pipe(pdes);
	pid_t pid = fork();
	if (pid == 0)
	{
		argv[argc - 1] = NULL;
		dup2(pdes[1], STDOUT_FILENO);
		close(pdes[1]);
		close(pdes[0]);
		ft_pipex(argc - 1, argv, env);
	}
	else
	{
		dup2(pdes[0], STDIN_FILENO);
		close(pdes[0]);
		close(pdes[1]);
		char **s = ft_split(argv[argc - 1], ' ');
		ft_which(&cmd, s[0], env);
		execve(cmd, s, env);
		perror(s[0]);
	}
}

int main(int argc, char *argv[], char *env[])
{
	printf("%d %s\n", argc, argv[argc - 1]);
	if (argc >= 5)
	{
		ft_pipex(argc - 1, argv, env);
	}
	return (0);
}