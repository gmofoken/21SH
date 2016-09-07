/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 08:21:17 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/03 09:29:03 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int				ft_len(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static void		ft_f_v(int i)
{
	int		j;

	j = 0;
	ft_putchar('\n');
	while (j++ <= i)
		ft_putchar(' ');
}

static int		ft_stop(char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strstr(s, "\\c");
	if (tmp != NULL)
		i = (ft_strlen(s) - ft_strlen(tmp));
	else
		i = ft_strlen(s);
	return (i);
}

static int	ft_check_flag(char c, int i)
{
	if (c == 'n')
		ft_putchar('\n');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'f' || c == 'v')
		ft_f_v(i);
	else if (c == 'e')
		return (4);
	else
	{
		ft_putchar('\\');
		return (2);
	}
	return (3);
}

int			ft_do_e(char *arg)
{
	int		l;
	int		b;
	int		i;

	i = 0;
	b = 1;
	l = ft_stop(arg) - 1;
	if (l != (int)ft_strlen(arg) - 1)
		b = 0;
	while (arg[i] != '\0' && i < l)
	{
		if (arg[i + 1] == '\\' && arg[i + 3] == 'b' && (i + 1) != l)
			i += 3;
		else if (arg[i + 1] == '\\' && (i + 1) != l)
		{
			ft_putchar(arg[i]);
			i += ft_check_flag(arg[i + 3], i);
		}
		else if (arg[i] != '\\' && arg[i] != '\"')
			ft_putchar(arg[i]);
		i++;
	}
	if (arg[i] != '\\' && arg[i] != '\"')
		ft_putchar(arg[i]);
	return (b);
}
