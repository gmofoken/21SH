/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 10:29:55 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/09 15:48:05 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

int				ft_close_p(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ')')
			return (0);
		i++;
	}
	return (1);
}

char			*ft_last(char *line)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen(line));
	i = 0;
	while (line[i] != ')')
	{
		str[i] = line[i];
		i++;
	}
	free(line);
	str[i] = '\0';
	return (str);
}

char			**ft_new_args(char **new_args)
{
	int		b;
	int		j;
	int		i;
	char	*line;

	new_args = ft_memalloc(25);
	b = 1;
	i = 0;
	j = 0;
	while (b != 0)
	{
		ft_putstr("subsh> ");
		line = ft_strtrim(get_line());
		while (line[j++] != '\0')
		{
			if (ft_close_p(line) == 0)
			{
				b = 0;
				line = ft_last(line);
			}
		}
		new_args[i++] = line;
	}
	new_args[i] = NULL;
	return (new_args);
}

void			ft_sub_s(t_data *data)
{
	ft_2d_free(data->args);
	data->args = ft_new_args(data->args);
}
