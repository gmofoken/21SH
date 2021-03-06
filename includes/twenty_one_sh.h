/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twenty_one_sh.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 09:51:27 by gmofoken          #+#    #+#             */
/*   Updated: 2016/09/09 12:29:46 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTY_ONE_SH_H
# define TWENTY_ONE_SH_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

typedef struct	s_data
{
	char	**env;
	void	**ptrs[100];
	int		n_ps;
	char	*line;
	char	**history[50];
	char	**args;
	int		brk;
	int		in;
	int		fd[2];
	char	**cmds;
}				t_data;

void			ft_run_s(t_data *data);
void			ft_free(t_data *data);
char			*get_line(void);
void			ft_run_args(t_data *data);
int				ft_s_args(t_data *data);
int				ft_cd(t_data *data);
void			ft_history(t_data *data);
void			ft_setenv(char *arg, char **env);
void			ft_echo(char **args);
char			**ft_echo_quo(char **args, int *e);
void			ft_putecho(char *s);
int				ft_do_e(char *arg);
int				ft_len(char **args);
void			ft_2d_free(char **arg);
char			*ft_realloc(char *str, char *str2);
void			ft_execute_env(char **env);
void			ft_sub_s(t_data *data);

#endif
