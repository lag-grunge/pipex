#include "pipex.h"

int	find_var_in_env(char *var, char *env[])
{
	size_t	i;
	size_t	p;
	char 	*s;
	size_t	var_len;

	i = 0;
	var_len = ft_strlen(var);
	while (env[i])
	{
		p = ft_strchr(env[i], '=') - env[i];
		s = ft_substr(env[i], 0, p);
		if (!ft_strncmp(s, var, var_len))
			return (i);
		i++;
	}
	return (-1);
}

static char *get_fp(char *dir, char *cmd)
{
	char	*fp;
	size_t	fp_len;
	size_t	dir_len;

	dir_len = ft_strlen(dir);
	fp_len = dir_len  + ft_strlen(cmd) + 1;
	fp = malloc(sizeof(char) * (fp_len + 1));
	ft_strlcpy(fp, dir, dir_len + 1);
	fp[dir_len] = '/';
	fp[dir_len + 1] = 0;
	ft_strlcat(fp, cmd, fp_len + 1);
	return (fp);
}

int	find_cmd_in_var(char *cmd, char *var)
{
	int		ret;
	size_t	i;
	char 	**s;
	char 	*fp;

	i = 0;
	s = ft_split(ft_strchr(var, '=') + 1, ':');
	ret = not_fnd_bin_in_path;
	while (ret && s[i])
	{
		fp = get_fp(s[i], cmd);
		if (access(fp, X_OK) == -1)
			ret = not_perms_for_exec;
		else
			ret = 0;
		free(fp);
		i++;
	}
	clean_split(s, ft_spllen(s));
	return (ret);
}

char *get_cmd(char *cmd, char *var)
{
	size_t	i;
	char 	**s;
	char 	*fp;

	i = 0;
	s = ft_split(ft_strchr(var, '=') + 1, ':');
	while (s[i])
	{
		fp = get_fp(s[i], cmd);
		if (access(fp, X_OK) != -1)
		{
			clean_split(s, ft_spllen(s));
			return (fp);
		}
		free(fp);
		i++;
	}
	clean_split(s, ft_spllen(s));
	return (NULL);
}

void ft_which(char **exec_path, char *cmd, char *env[])
{
	int	var_num;
	int	find_cmd;

	if (ft_strchr(cmd, '/'))
	{
		*exec_path = cmd;
		return ;
	}
	var_num = find_var_in_env("PATH", env);
	if (var_num == -1)
	{
		perror(BAD_ENV_MSG);
		exit(nopath_in_env);
	}
	find_cmd = find_cmd_in_var(cmd, env[var_num]);
	if (find_cmd == not_perms_for_exec)
		perror(PERM_DENIAL_MSG);
	else if (find_cmd == not_fnd_bin_in_path)
		perror(BIN_NOT_FOUND_MSG);
	if (find_cmd)
		exit(find_cmd);
	*exec_path = get_cmd(cmd, env[var_num]);
}
