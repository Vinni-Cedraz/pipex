/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_second_child_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:44:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/09 17:09:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			execute_second_command(t_data *d);
static void			redirect_stdin_to_piperead(t_data *d);
static void			redirect_stdout_to_output_fd(t_data *d);

void	run_second_child_process(t_data *d)
{
	close(d->file_descriptors.fd[WRTE_SIDE]);
	redirect_stdin_to_piperead(d);
	close(d->file_descriptors.input_fd);
	redirect_stdout_to_output_fd(d);
	execute_second_command(d);
	close(d->file_descriptors.output_fd);
	close(d->file_descriptors.fd[READ_SIDE]);
}

static inline void	execute_second_command(t_data *d)
{
	execve(d->execve.full_cmd2, d->execve.str_arr2, NULL);
}

static inline void	redirect_stdin_to_piperead(t_data *d)
{
	if (-1 == dup2(d->file_descriptors.fd[READ_SIDE], STDIN_FILENO))
		handle_error(d, "third dup", &free_error4);
}

static inline void	redirect_stdout_to_output_fd(t_data *d)
{
	if (-1 == dup2(d->file_descriptors.output_fd, STDOUT_FILENO))
		handle_error(d, "fourth dup", &free_error4);
}
