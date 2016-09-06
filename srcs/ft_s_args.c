/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 13:11:45 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/07 17:56:17 by gmofoken         ###   ########.fr       */
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
	{
		c = 1;
		//ft_echo(data);
	}
	return (c);
}
