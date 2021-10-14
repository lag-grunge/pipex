#include "pipex.h"


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
	if (!ft_strncmp(HEREDOC, argv[1], ft_strlen(HEREDOC)))
		*fd_in = STDIN_FILENO;
	else
	{
		*fd_in = open(argv[1], O_RDONLY);
		if (*fd_in == -1) {
			perror(argv[1]);
			exit(file1_not_open);
		}
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

void ft_pipex_bonus(int fd_in_out[2], int argc, char *argv[], char *env[])
{
	static int	**pdes;
	pid_t		pid;
	int			in_out;

	if (fd_in_out[0] == STDIN_FILENO && argc == (int)ft_spllen(argv) - 4)
	{
		pdes = (int **)malloc(sizeof(int [2]) * (argc - 1));
		in_out = last;
	}
	else if (fd_in_out[0] != STDIN_FILENO && argc == (int)ft_spllen(argv) - 3)
	{
		pdes = (int **)malloc(sizeof(int [2]) * (argc - 1));
		in_out = last;
	}
	else if (!argc)
	{
		int ret;

		ft_redirect_bonus(fd_in_out, pdes[argc - 1], parent);
		while (ret != -1)
			ret = wait(NULL);
		free(pdes);
		return ;
	}
	else
		in_out = STDIN_FILENO;
	if (pipe(pdes[argc - 1]) == -1)
		exit(pipe_fail);
	pid = fork();
	if (pid < 0)
		exit(fork_fail);
	else if (pid == 0)
	{
		ft_redirect_bonus(fd_in_out, pdes[argc - 1], in_out);
		ft_exec(argv[argc - 1], env);
		perror(argv[argc - 1]);
		exit(cmd_exec_fail);
	}
	in_out = STDOUT_FILENO;
	if (argc == 1)
		in_out = first;
	ft_redirect_bonus(fd_in_out, pdes[argc - 1], in_out);
	ft_pipex_bonus(fd_in_out, argc - 1, argv, env);
}

int main(int argc, char *argv[], char *env[])
{
	int fd[2];

	fd[0] = 0;
	fd[1] = 0;
	ft_openfiles(&fd[0], &fd[1], argv);
	if (fd[0] == STDIN_FILENO && argc >= 6)
		ft_pipex_bonus(fd, argc - 4, argv, env);
	else if (fd[0] != STDIN_FILENO && argc >= 5)
		ft_pipex_bonus(fd, argc - 3, argv, env);
	return (0);
}