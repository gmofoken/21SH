/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:24:19 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/22 13:33:57 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static void	ft_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putstr(envp[i]);
		ft_putchar('\n');
		i++;
	}
}

int			env_mod(char **args, char **envp)
{
	if (ft_strcmp(args[0], "env") == 0)
		ft_env(envp);
	else if (ft_strcmp(args[0], "setenv") == 0 && ft_len(args) > 1)
		ft_setenv(args[1], envp);
	else if (ft_strcmp(args[0], "unsetenv") == 0 && ft_len(args) > 1)
		ft_unsetenv(envp, args[1]);
	return (2);
}
