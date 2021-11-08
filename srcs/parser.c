/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 08:16:33 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/21 08:16:35 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *env[])
{
	size_t	i;
	size_t	p;

	i = 0;
	while (env[i])
	{
		p = ft_strchr(env[i], '=') - env[i];
		if (p == 4)
			if (!ft_strncmp("PATH", env[i], 4))
				break ;
		i++;
	}
	return (env[i]);
}

static char	*get_fp(char *dir, char *cmd)
{
	char	*fp;
	size_t	fp_len;
	size_t	dir_len;

	dir_len = ft_strlen(dir);
	fp_len = dir_len + ft_strlen(cmd) + 1;
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
	char	**s;
	char	*fp;

	i = 0;
	s = ft_split(ft_strchr(var, '=') + 1, ':');
	ret = not_fnd_bin_in_path;
	while (ret && s[i])
	{
		fp = get_fp(s[i], cmd);
		if (ret == not_fnd_bin_in_path && !access(fp, F_OK))
			ret = not_perms_for_exec;
		if (ret == not_perms_for_exec && !access(fp, X_OK))
			ret = 0;
		free(fp);
		i++;
	}
	clean_split(s, ft_spllen(s));
	return (ret);
}

char	*get_cmd(char *cmd, char *var)
{
	size_t	i;
	char	**s;
	char	*fp;

	i = 0;
	s = ft_split(ft_strchr(var, '=') + 1, ':');
	while (s[i])
	{
		fp = get_fp(s[i], cmd);
		if (!access(fp, X_OK))
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

void	ft_which(char **exec_path, char *cmd, char *env[])
{
	char	*path_str;
	int		find_cmd;

	if (ft_strchr(cmd, '/'))
	{
		*exec_path = cmd;
		return ;
	}
	path_str = find_path(env);
	if (path_str == NULL)
	{
		write(2, BAD_ENV_MSG, ft_strlen(BAD_ENV_MSG));
		exit(nopath_in_env);
	}
	find_cmd = find_cmd_in_var(cmd, path_str);
	if (find_cmd == not_perms_for_exec)
		perror(cmd);
	else if (find_cmd == not_fnd_bin_in_path)
		perror(cmd);
	if (find_cmd)
		exit(find_cmd);
	*exec_path = get_cmd(cmd, path_str);
	if (!*exec_path)
		exit(not_perms_for_exec);
}
