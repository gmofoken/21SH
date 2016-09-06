/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 09:51:43 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/07 16:51:15 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void	ft_run_s(t_data *data)
{
	data->brk = 1;
	ft_putendl("\t\t\t\tKG_SHELL V2.1SH\n\n");
	while (data->brk != 0)
	{
		ft_putstr("KG_SHELL$ ");
		data->line = get_line();
		data->args = ft_strsplit(data->line, ';');
		if (ft_strlen(data->line) > 0 && data->args[0] != NULL)
		{
			ft_history(data);
			if (ft_strcmp(*data->args, "exit") == 0)
				data->brk = 0;
			else if (ft_strcmp(*data->args, "exit") != 0)
				data->n_ps = ft_s_args(data);
			if (data->n_ps == 1)
				ft_run_args(data);
		}
	}
}
