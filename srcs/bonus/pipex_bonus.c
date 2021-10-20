#include "pipex.h"

static int ft_openfiles(int argc, char *argv[])
{
    int fd_in;
    int fd_out;
    int cmd_start;

    cmd_start = 2;
    if (!ft_strncmp(HEREDOC, argv[1], ft_strlen(HEREDOC)))
    {
		read_here_doc(argv[2]);
		fd_in = open_for_read("heredoc");
        cmd_start = 3;
    }
	else
		fd_in = open_for_read(argv[1]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	fd_out = open_for_write(argv[argc - 1]);
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
    return (cmd_start);
}

static int** pipe_alloc(int cmds_num)
{
	int	i;
	int	**pipe_array;

	pipe_array = (int **)malloc(sizeof(int *) * (cmds_num - 1));
	if (!pipe_array)
		exit(malloc_error);
	i = 0;
	while (i < cmds_num - 1)
	{
		pipe_array[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipe_array[i])
		{
			free_2d_array(pipe_array, i);
			exit(malloc_error);
		}
		i++;
	}
	return (pipe_array);
}

static void ft_child_exec(int i, int **pdes, char *cmd, char *env[])
{
	if (i > 1)
		ft_redirect(pdes[i - 2], STDIN_FILENO);
	ft_exec(cmd, env);
	perror(cmd);
	exit(cmd_exec_fail);
}

static void ft_pipex(int cmd_start, int cmds_num, char *argv[], char *env[])
{
	int     **pdes;
	pid_t	pid;
    int     ret;
	int		i;

    pdes = pipe_alloc(cmds_num);
	ret = 1;
	i = cmds_num;
    while (i)
    {
        if (i > 1 && pipe(pdes[i - 2]) == -1)
            exit(pipe_fail);
        pid = fork();
        if (pid < 0)
            exit(fork_fail);
        else if (pid == 0)
			ft_child_exec(i, pdes, argv[cmd_start + i - 1], env);
		if (i > 1)
        	ft_redirect(pdes[i - 2], STDOUT_FILENO);
		i--;
    }
	ft_redirect(pdes[0], -1);
    while (ret != -1)
		ret = wait(NULL);
	free_2d_array(pdes, cmds_num - 1);
}

int main(int argc, char *argv[], char *env[])
{
    int cmd_start_arg;

    cmd_start_arg = ft_openfiles(argc, argv);
    if (argc < 5 || (cmd_start_arg == 3 && argc == 5))
    {
        write(STDERR_FILENO, ARG_ERROR_MSG, ft_strlen(ARG_ERROR_MSG));
        return (argv_error);
    }
    if (cmd_start_arg == 3)
        ft_pipex(cmd_start_arg, argc - 4, argv, env);
    else
        ft_pipex(cmd_start_arg, argc - 3, argv, env);
    return (0);
}
