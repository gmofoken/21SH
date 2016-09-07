/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:45:52 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/22 11:54:04 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void		ft_unsetenv(char **env, char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (env[nbr])
		nbr++;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str) - 1) == 0)
		{
			while (i < nbr - 1)
			{
				env[i] = ft_realloc(env[i], env[i + 1]);
				i++;
			}
			if (env[i] != NULL)
				env[i] = ft_realloc(env[i], NULL);
		}
		i++;
	}
}

static int	ft_import_env(char **environ, char **env, char *str)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(str, environ[i], ft_strlen(str) - 1) == 0)
		{
			ft_setenv(environ[i], env);
			return (0);
		}
		i++;
	}
	return (1);
}

void		ft_resetenv(char **env, char *str)
{
	int			i;
	char		**arg;
	extern char	**environ;

	i = 0;
	arg = ft_strsplit(str, ' ');
	if (ft_strncmp(arg[1], "all", 3) == 0)
	{
		while (environ[i])
		{
			env[i] = ft_realloc(env[i], environ[i]);
			i++;
		}
	}
	else
	{
		if (ft_import_env(environ, env, arg[1]) == 0)
			ft_execute_env(env);
		else
			ft_putstr(" Error! Variable does not exist.\n");
	}
	ft_2d_free(arg);
}

void		ft_2d_free(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		arg[i] = ft_realloc(arg[i], NULL);
		i++;
	}
	free(arg);
	arg = NULL;
}
