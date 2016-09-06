/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:30:09 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/07 15:33:10 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

int	main(void)
{
	extern char	**environ;
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->n_ps = 0;
	data->env = environ;
	ft_run_s(data);
	return (0);
}
