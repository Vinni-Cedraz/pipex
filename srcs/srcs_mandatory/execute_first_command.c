/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_first_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:22:31 by vcedraz-          #+#    #+#             */
/* j Updated: 2023/03/06 16:01:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			init_args_args(t_data *d);
static void			destroy_args_args(t_data *d);

void	execute_first_command(t_data *d)
{
	d->pipe.full_cmd1 = ft_strjoin(d->args.cmd1, ft_strdup("/usr/bin/"));
	init_args_args(d);
	execve(d->pipe.full_cmd1, d->args.args, NULL);
	destroy_args_args(d);
}

static inline void	init_args_args(t_data *d)
{
	t_args	*args;

	args = &d->args;
	args->args = malloc(3 * sizeof(char *));
	args->args[0] = d->pipe.full_cmd1;
	args->args[1] = ft_strdup(args->file1);
	args->args[2] = NULL;
}

static void	destroy_args_args(t_data *d)
{
	ft_free_arr(d->args.args, (void **)d->args.args);
}
