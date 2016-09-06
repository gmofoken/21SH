/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:28:13 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/07 16:48:24 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void	ft_history(t_data *data)
{
	static int		i;

	i = 0;
	while (data->history[i] != NULL)
		i++;
	data->history[i++] = &data->line;
	data->history[i] = NULL;
}
