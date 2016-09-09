/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 13:11:45 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/09 12:29:30 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

int		ft_s_args(t_data *data)
{
	int		c;

	c = 1;

	if (ft_strcmp(*data->args, "cd") == 0)
		c = ft_cd(data);
	if (ft_strcmp(*data->args, "echo") == 0)
		ft_echo(data->args);
	if (ft_strcmp(*data->args, "(") == 0)
		ft_sub_s(data);	
	return (c);
}
