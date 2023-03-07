/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:33:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 13:19:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	init_data(d, argv, argc);
	create_pipe(d);
	open_input_file(d);
	open_output_file(d);
	create_child_process(d);
	if (is_child_process(d->fork.id))
	{
		redirect_stdin_to_file_one(d);
		redirect_stdout_to_pipe(d);
		execute_first_command(d);
	}
	create_child_process(d);
	if (is_child_process(d->fork.id))
	{
		redirect_stdin_to_pipe(d);
		redirect_stdout_to_file_two(d);
		execute_second_command(d);
	}
	else
	{
		wait(0);
		destroy_data(d);
	}
}
