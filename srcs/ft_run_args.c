/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 11:38:26 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/07 16:14:44 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static char	*find(char *name)
{
	char	*path;
	char	*tmp1;
	char	**folders;
	char	**tmp2;

	folders = ft_strsplit(getenv("PATH"), ':');
	tmp2 = folders;
	while (*folders != '\0')
	{
		tmp1 = ft_strjoin(*folders, "/");
		path = ft_strjoin(tmp1, name);
		if (access(path, F_OK) == 0)
		{
			return (path);
		}
		folders++;
	}
	return (NULL);
}

static int	n_pipes(char **pipes)
{
	int		loop;

	loop = 0;
	while (pipes[loop] != '\0')
		loop++;
	return (loop);
}

static void	pipe_function(char **args, int in, int out, char **environ)
{
	pid_t	pid;
	int		stat;

	if ((pid = fork()) == 0)
	{
		if (in != 0)
		{
			dup2(in, 0);
			close(in);
		}
		if (out != 1)
		{
			dup2(out, 1);
			close(out);
		}
		execve(find(args[0]), args, environ);
	}
	else if (pid > 0)
	{
		waitpid(pid, &stat, WUNTRACED);
		while (!WIFEXITED(stat) && !WIFSIGNALED(stat))
			waitpid(pid, &stat, WUNTRACED);
	}
}

static void	execute(char *cmds, t_data *data)
{
	char		**pipes;
	char		**args;
	int			loop;
	int			in;
	int			fd[2];

	pipes = ft_strsplit(cmds, '|');
	loop = 0;
	in = 0;
	while (loop < n_pipes(pipes) - 1)
	{
		pipe(fd);
		args = ft_strsplit(pipes[loop], ' ');
		pipe_function(args, in, fd[1], data->env);
		in = fd[0];
		close(fd[1]);
		loop++;
	}
	if (in != 0)
		dup2(in, 0);
	args = ft_strsplit(pipes[loop], ' ');
	execve(find(args[0]), args, data->env);
}

void		ft_run_args(t_data *data)
{
	pid_t	pid;
	int		stat;

	while (*data->args != '\0')
	{
		if ((pid = fork()) == 0)
			execute(*data->args, data);
		else if (pid > 0)
		{
			waitpid(pid, &stat, WUNTRACED);
			while (!WIFEXITED(stat) && !WIFSIGNALED(stat))
				waitpid(pid, &stat, WUNTRACED);
		}
		data->args++;
	}
}
