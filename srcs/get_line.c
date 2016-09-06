/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 17:19:34 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/07 09:39:50 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static char		get_char(void)
{
	char	chr;

	read(0, &chr, 1);
	return (chr);
}

static char		*resize_str(char *str, int size)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(size);
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	free(str);
	return (arr);
}

char			*get_line(void)
{
	char	*line;
	char	c;
	int		i;
	int		size;

	size = 1024;
	line = (char *)malloc(size);
	i = 0;
	while (1)
	{
		c = get_char();
		if (c == '\n' || c == '\0')
		{
			line[i] = '\0';
			return (line);
		}
		if (size - 1 <= i)
		{
			size = size * 2;
			line = resize_str(line, size);
		}
		line[i] = c;
		i++;
	}
	return (line);
}
