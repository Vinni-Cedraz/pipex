/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_first_child_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:43:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/12 16:04:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			execute_first_command(t_data *d);
static void			redirect_stdout_to_pipewrte(t_data *d);
static void			redirect_stdin_to_input_fd(t_data *d);

void	run_first_child_process(t_data *d)
{
	close(d->file_descriptors.fd[READ_SIDE]);
	redirect_stdout_to_pipewrte(d);
	close(d->file_descriptors.output_fd);
	redirect_stdin_to_input_fd(d);
	execute_first_command(d);
}

static inline void	redirect_stdout_to_pipewrte(t_data *d)
{
	if (d->execve.cmd1_is_nil)
		ft_putendl_fd("", d->file_descriptors.fd[WRTE_SIDE]);
	else if (-1 == dup2(d->file_descriptors.fd[WRTE_SIDE], STDOUT_FILENO))
		handle_error(d, "first dup", &custom_free3, 2);
}

static inline void	redirect_stdin_to_input_fd(t_data *d)
{
	if (d->execve.cmd1_is_nil)
		close(d->file_descriptors.input_fd);
	else if (-1 == dup2(d->file_descriptors.input_fd, STDIN_FILENO))
		handle_error(d, "second dup", custom_free3, 2);
}

static inline void	execute_first_command(t_data *d)
{
	if (d->execve.cmd1_is_nil)
		return ;
	execve(d->execve.full_cmd1, d->execve.str_arr1, d->args.envp);
}
