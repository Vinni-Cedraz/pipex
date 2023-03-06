/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_first_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:22:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 18:22:31 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			init_args_args(t_data *d);
static void			destroy_args_args(t_data *d);

void	execute_first_command(t_data *d)
{
	int	cmdlen;

	cmdlen = ft_strlen(d->args.cmd1) + ft_strlen("/usr/bin/") + 1;
	d->pipe.full_cmd1 = malloc(cmdlen * sizeof(char));
	ft_strlcpy(d->pipe.full_cmd1, "/usr/bin/", cmdlen);
	ft_strlcat(d->pipe.full_cmd1, d->args.cmd1, cmdlen);
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
