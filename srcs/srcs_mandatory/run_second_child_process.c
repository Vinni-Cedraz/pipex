/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_second_child_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:44:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 15:20:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_second_child_process(t_data *d)
{
	create_child_process(d);
	if (!is_child_process(d->fork.id))
		return ;
	close(d->file_descriptors.fd[WRTE_SIDE]);
	redirect_stdin_to_pipe(d);
	redirect_stdout_to_file_two(d);
	execute_second_command(d);
	close(d->file_descriptors.fd[READ_SIDE]);
}
