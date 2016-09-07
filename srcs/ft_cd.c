/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:34:05 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/28 16:14:05 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

char		*env_attr(char **envp, char *attr)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (envp[i] && b == 0)
	{
		if (ft_strncmp(envp[i], attr, ft_strlen(attr)) == 0)
			b = 1;
		i++;
	}
	i--;
	return (ft_strstr(envp[i], "/"));
}

char		*unique_dir(char *arg, char **env)
{
	return (ft_strjoin(env_attr(env, "HOME"), ft_strstr(arg, "/")));
}

static void	travel(char **env, char *dir, char **args)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strcmp(dir, "OLD") == 0)
	{
		ft_putendl(env_attr(env, "OLDPWD"));
		tmp = ft_strjoin("OLDPWD=", env_attr(env, "PWD"));
		ft_setenv(ft_strjoin("PWD=", env_attr(env, "OLDPWD")), env);
		ft_setenv(tmp, env);
	}
	else if (ft_strcmp(dir, "HOME") == 0)
	{
		tmp = ft_strjoin("OLDPWD=", env_attr(env, "PWD"));
		ft_setenv(ft_strjoin("PWD=", env_attr(env, "HOME")), env);
		ft_setenv(tmp, env);
	}
	else if (ft_strcmp(dir, unique_dir(args[1], env)) == 0)
	{
		tmp = ft_strjoin("OLDPWD=", env_attr(env, "PWD"));
		ft_setenv(ft_strjoin("PWD=", unique_dir(args[1], env)), env);
		ft_setenv(tmp, env);
	}
}

void		ft_cd_fnl(char **args)
{
	int		i;

	i = chdir(args[1]);
	if (i != 0)
		ft_putendl(ft_strjoin("cd: no such file or directory: ", args[1]));
}

int			ft_cd(t_data *data)
{
	int		i;

	i = 0;
	if (ft_len(data->args) > 1 && ft_strcmp(data->args[1], "?") == 0)
		ft_putendl("zsh: no matches found: ?");
	else if (ft_len(data->args) > 1 && ft_strncmp(data->args[1], "~/", 2) == 0)
	{
		i = chdir(unique_dir(data->args[1], data->env));
		if (i == 0)
			travel(data->env, unique_dir(data->args[1], data->env), data->args);
	}
	else if (ft_len(data->args) == 1 || ft_strcmp(data->args[1], "~") == 0)
	{
		chdir(env_attr(data->env, "HOME"));
		travel(data->env, "HOME", data->args);
	}
	else if (ft_strcmp(data->args[1], "-") == 0)
	{
		chdir(env_attr(data->env, "OLDPWD"));
		travel(data->env, "OLD", data->args);
	}
	else
		ft_cd_fnl(data->args);
	return (1);
}
