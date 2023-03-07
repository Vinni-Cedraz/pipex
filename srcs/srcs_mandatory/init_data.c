/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:36:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 21:43:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static inline void	check_argc_validity(t_data *d, int argc);
static inline void	init_execve_argvs(t_data *d);

void	init_data(t_data *d, char **argv, int argc)
{
	t_args	*args;

	check_argc_validity(d, argc);
	d->split = ft_split(argv[3], 32);
	args = &d->args;
	args->file1 = argv[1];
	args->cmd1 = argv[2];
	args->cmd2 = d->split->str_arr[0];
	args->cmd2_arg = d->split->str_arr[1];
	args->file2 = argv[4];
	get_full_cmds_paths(d);
	init_execve_argvs(d);
}

static inline void	init_execve_argvs(t_data *d)
{
	t_execve	*execve;

	execve = &d->execve;
	execve->cmd1_argv = malloc(3 * sizeof(char *));
	execve->cmd2_argv = malloc(4 * sizeof(char *));
	execve->cmd1_argv[0] = d->pipe.full_cmd1;
	execve->cmd1_argv[1] = ft_strdup(d->args.file1);
	execve->cmd1_argv[2] = NULL;
	execve->cmd2_argv[0] = d->pipe.full_cmd2;
	execve->cmd2_argv[1] = ft_strdup(d->args.cmd2_arg);
	execve->cmd2_argv[2] = ft_strdup(d->args.file2);
	execve->cmd2_argv[3] = NULL;
}

void	destroy_data(t_data *d)
{
	ft_free_arr(d->execve.cmd1_argv, (void **)d->execve.cmd1_argv);
	ft_free_arr(d->execve.cmd2_argv, (void **)d->execve.cmd2_argv);
	ft_free_arr(d->split->str_arr, (void **)d->split->str_arr);
	close(d->pipe.input_fd);
	close(d->pipe.output_fd);
	free(d->split);
	free(d->args.cmd2);
	free(d->args.cmd2_arg);
	free(d);
}

static inline void	check_argc_validity(t_data *d, int argc)
{
	if (argc != 5)
		handle_error(d, "Wrong number of arguments");
}
