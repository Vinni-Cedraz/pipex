/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:33:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 20:30:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	init_data(d, argv, argc);
	create_pipe(d);
	create_child_process(d);
	if (is_child_process(d->fork.id))
	{
		open_input_file(d);
		redirect_stdin_to_file_one(d);
		redirect_stdout_to_pipe(d);
		execute_first_command(d);
		close(d->pipe.input_fd);
	}
	else
	{
		wait(0);
		open_output_file(d);
		redirect_stdin_to_pipe(d);
		redirect_stdout_to_file_two(d);
		execute_second_command(d);
		close(d->pipe.output_fd);
		destroy_args_args(d);
		free(d);
	}
}
